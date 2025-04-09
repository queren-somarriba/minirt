/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:17:38 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/09 11:35:18 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	make_vect_dir(t_minirt *data, float x, float y)
{
	t_vector	v_dir;
	t_vector	up;
	t_vector	right;
	float		f[3];

	up = (t_vector){0.0, 1.0, 0.0};
	right = mult_vect(up, *data->cam->v);
	up = mult_vect(*data->cam->v, right);
	f[0] = x + 0.5 - WIN_WIDTH * 0.5;
	f[1] = y + 0.5 - WIN_HEIGHT * 0.5;
	f[2] = WIN_HEIGHT;
	if (WIN_WIDTH > WIN_HEIGHT)
		f[2] = WIN_WIDTH;
	f[2] /= (2 * tanf((data->cam->fov * 0.5) * M_PI / 180.0));
	v_dir.x = data->cam->v->x * f[2] + right.x * f[0] + up.x * f[1];
	v_dir.y = data->cam->v->y * f[2] + right.y * f[0] + up.y * f[1];
	v_dir.z = data->cam->v->z * f[2] + right.z * f[0] + up.z * f[1];
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
