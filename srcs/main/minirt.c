/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:03:34 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/21 17:38:11 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2 || !ft_str_equal(argv[1] + ft_strlen(argv[1]) - 3, ".rt"))
		return (ft_putstr_fd(FILE_ERROR, 2), EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd(argv[1], 2), ft_putstr_fd(OPEN_ERROR, 2), 1);
	return (close(fd), EXIT_SUCCESS);
}

int	init_minirt(t_minirt *data)
{
	data->objects = ft_calloc(1, sizeof(t_list *));
	if (!data->objects)
		return (perror("malloc"), EXIT_FAILURE);
	data->scene = ft_calloc(1, sizeof(t_scene));
	if (!data->scene)
		return (perror("malloc"), free_minirt(data), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_minirt	data;

	if (check_args(argc, argv))
		return (EXIT_FAILURE);
	if (init_minirt(&data))
		return (EXIT_FAILURE);
	if (pars_file(&data, argv[1]))
		return (EXIT_FAILURE);
	/*loop mlx...*/
	free_minirt(&data);
	return (EXIT_SUCCESS);
}
