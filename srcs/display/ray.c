/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:17:38 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/10 18:58:05 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	make_vect_dir(t_minirt *data, float x, float y)
{
	t_vector	v_dir;
	float		a;
	float		b;
	float		c;

	a = x + 0.5 - WIN_WIDTH * 0.5;
	b = y + 0.5 - WIN_HEIGHT * 0.5;
	c = WIN_HEIGHT;
	if (WIN_WIDTH > WIN_HEIGHT)
		c = WIN_WIDTH;
	c /= (2 * tanf((data->cam->fov * 0.5) * M_PI / 180.0));
	v_dir = (t_vector){a, b, c};
	return (normalize_vect(v_dir));
}

void	ray_tracer(t_minirt *data)
{
	float	x;
	float	y;
	t_ray	ray;
	t_inter	*inter;

	x = -1.0;
	while (++x < WIN_WIDTH)
	{
		y = -1.0;
		while (++y < WIN_HEIGHT)
		{
			ray.p = *data->cam->p;
			ray.v = make_vect_dir(data, x, y);
			inter = closest_inter(data, ray);
			if (inter)
				inter->c = final_color(data, inter);
			if (inter)
			{
				img_pix_put(data->img, x, y, encode_rgb(inter->c));
				free(inter);
			}
		}
	}
}
