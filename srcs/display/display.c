/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiech <jpiech@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:23:40 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/27 14:47:01 by jpiech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	img_pix_put(t_img img, int x, int y, int color)
{
	char	*pixel;

	pixel = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(int *)pixel = color;
}

int	render(t_minirt *data)
{
	if (!data->win_ptr)
		return (1);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (EXIT_SUCCESS);
}
