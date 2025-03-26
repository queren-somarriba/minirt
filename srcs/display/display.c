/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:23:40 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/26 19:43:57 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	encode_rgb(t_color *c)
{
	return (c->r << 16 | c->g << 8 | c->b);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	scale(int x)
{
	if (x < 100)
		return (0);
	else if (x < 200)
		return (1);
	else if (x < 300)	
		return (0);
	else if (x < 400)
		return (1);
	else if (x < 500)
		return (0);
	else if (x < 600)
		return (1);
	else if (x < 700)
		return (0);
	else if (x < 800)
		return (1);
	return (0);
}

int	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			color = (i * 255 / WIN_HEIGHT) << 8 | (j * 255 / WIN_WIDTH) << 0;
			if (scale(i) && scale(j))
				img_pix_put(img, j, i, color);
			j++;
		}
		i++;
	}
	return (0);
}

double	dist(int i, int j, int x, int y)
{
	double	res;

	res = sqrt(pow(abs(x - i), 2.0) + pow(abs(y - j), 2.0));
	return (res);
}

int	render_circle(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (dist(i, j, 500, 500) < 100)
			{
				color = (i * 255 / WIN_WIDTH) << 8
					| (j * 255 / WIN_HEIGHT) << 16;
				img_pix_put(img, j, i, color);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	render_dam(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (i > 100 && i < 400 && j > 100 && j < 400
				&& i % 2 == 0 && j % 2 == 0)
				img_pix_put(img, j, i, color);
			j++;
		}
		i++;
	}
	return (0);
}

int	render(t_minirt *data)
{
	if (!data->win_ptr)
		return (1);
	render_background(&data->img, 0xFFFFFF);
	render_dam(&data->img, 0xFF0000);
	render_circle(&data->img, 0xFF00FF);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

// int	render(t_minirt *data)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = -1;
// 	if (!data->win_ptr)
// 		return (EXIT_SUCCESS);
// 	while (++i <= WIN_WIDTH)
// 	{
// 		j = -1;
// 		while( ++j <= WIN_HEIGHT)
// 		{
// 			if (i <= 100 && j <= 100)
// 				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0xFF00FF);
// 			else if (i <= 100 && j >= WIN_HEIGHT - 100)
// 				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0xFFFF00);
// 			else if (i >= WIN_WIDTH - 100 && j <= 100)
// 				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0x00FFFF);
// 			else if (i >= WIN_WIDTH - 100 && j >= WIN_HEIGHT - 100)
// 				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0xFFFFFF);
// 			else if (i >= (WIN_WIDTH - 100) / 2 && i <= (WIN_WIDTH + 100) / 2
// 				&& j >= (WIN_HEIGHT - 100) / 2 && j < (WIN_HEIGHT + 100) / 2)	
// 				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0xFF0000);
// 			else if ( i == j || WIN_WIDTH - i == WIN_HEIGHT - j
// 				|| i  == WIN_HEIGHT - j || j == WIN_WIDTH - i)
// 				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0x00FF00);
// 			else
// 				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0x0000FF);
// 		}
// 	}
// 	return (EXIT_SUCCESS);
// }
