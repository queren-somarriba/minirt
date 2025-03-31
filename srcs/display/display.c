/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:23:40 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/31 18:15:12 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	encode_rgb(t_color c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}

void	img_pix_put(t_img img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img.bpp - 8;
	pixel = img.addr + (y * img.line_len + x * (img.bpp / 8));
	while (i >= 0)
	{
		if (img.endian)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img.bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render(t_minirt *data)
{
	if (!data->win_ptr)
		return (1);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}
