/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:17:38 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/11 19:50:27 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	make_vect_dir(t_minirt *data, float x, float y)
{
	t_vector	forw;
	t_vector	right;
	t_vector	up;
	float		f[4];
	t_vector	v_cam;

	f[0] = (float)WIN_WIDTH / WIN_HEIGHT;
	f[1] = tanf((data->cam->fov * 0.5) * M_PI / 180.0);
	f[2] = (2 * (x + 0.5) / WIN_WIDTH - 1) * f[0] * f[1];
	f[3] = (1 - 2 * (y + 0.5) / WIN_HEIGHT) * f[1];
	forw = normalize_vect(*data->cam->v);
	if (fabsf(forw.x) == 0 && fabsf(forw.z) == 0)
		right = (t_vector){1, 0, 0};
	else
		right = normalize_vect(mult_vect((t_vector){0, 1, 0}, forw));
	up = mult_vect(forw, right);
	v_cam = add_vector(add_vector(vector_scale(right, f[2]),
			vector_scale(up, f[3])), forw);
	return (normalize_vect(v_cam));
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
