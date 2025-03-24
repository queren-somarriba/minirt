/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:03:34 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/24 19:10:34 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2 || !ft_str_equal(argv[1] + ft_strlen(argv[1]) - 3, ".rt"))
		return (printerr(FILE_ERROR), EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (printerr("Error\n"), printerr2(argv[1], OPEN_ERROR), 1);
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
		return (free_minirt(&data), EXIT_FAILURE);
	print_scene(&data);
	print_objects(data.objects);
	/*loop mlx...*/
	free_minirt(&data);
	return (EXIT_SUCCESS);
}
