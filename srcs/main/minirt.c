/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:03:34 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/23 18:51:18 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_args(int argc, char **argv)
{
	int	fd;

	if (WIN_HEIGHT <= 0 || WIN_WIDTH <= 0)
		return (printerr(WINDOW_ERROR), EXIT_FAILURE);
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
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (free_minirt(data), printerr(MLX_INIT), EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, ":)");
	if (!data->win_ptr)
		return (free_minirt(data), printerr(MLX_WIN), EXIT_FAILURE);
	data->img.mlx_img = NULL;
	data->amb = NULL;
	data->cam = NULL;
	data->light = NULL;
	data->current_obj = 0;
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
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	ray_tracer(&data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_input, &data);
	mlx_hook(data.win_ptr, DestroyNotify, 1L << 17, &free_minirt, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
