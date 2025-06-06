/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:03:53 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/25 15:07:35 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_scene(char *str)
{
	char	buff;
	int		fd;
	size_t	count[3];

	ft_bzero(count, sizeof(count));
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (perror("open"), EXIT_FAILURE);
	while (read(fd, &buff, 1))
	{
		if (buff == 'A')
			count[0] += 1;
		if (buff == 'C')
			count[1] += 1;
		if (buff == 'L')
			count[2] += 1;
	}
	if (count[0] != 1)
		return (close(fd), printerr(AMB_ERROR), 1);
	if (count[1] != 1)
		return (close(fd), printerr(CAM_ERROR), 1);
	if (count[2] != 1)
		return (close(fd), printerr(LIGHT_ERROR), 1);
	return (close(fd), EXIT_SUCCESS);
}

static int	pars_line(t_minirt *data, char *str, int count)
{
	char	**arr;
	int		res;

	if (str_is_white_space(str))
		return (EXIT_SUCCESS);
	arr = ft_split(str, ' ');
	if (!arr)
		return (perror("malloc"), EXIT_FAILURE);
	if (ft_str_equal(*arr, "A"))
		res = pars_ambient_light(data, arr, count);
	else if (ft_str_equal(*arr, "C"))
		res = pars_camera(data, arr, count);
	else if (ft_str_equal(*arr, "L"))
		res = pars_light(data, arr, count);
	else if (ft_str_equal(*arr, "sp"))
		res = pars_sphere(data, arr, count);
	else if (ft_str_equal(*arr, "pl"))
		res = pars_plane(data, arr, count);
	else if (ft_str_equal(*arr, "cy"))
		res = pars_cylindre(data, arr, count);
	else
		return (ft_free_array(arr), printerr_line(count, SCENE_ERROR), 1);
	return (ft_free_array(arr), res);
}

int	pars_file(t_minirt *data, char *str)
{
	int		fd;
	int		res;
	int		count_lines;
	char	*line;

	res = 0;
	count_lines = 1;
	if (check_scene(str))
		return (EXIT_FAILURE);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (perror("open"), EXIT_FAILURE);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), EXIT_FAILURE);
	while (line)
	{
		if (pars_line(data, line, count_lines))
			res = 1;
		free(line);
		line = get_next_line(fd);
		count_lines++;
	}
	return (close(fd), res);
}
