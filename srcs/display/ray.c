/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiech <jpiech@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:17:38 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/27 20:12:52 by jpiech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	make_vect_dir(t_minirt *data, float x, float y)
{
	float		f[4];
	t_vector	v_cam;

	f[0] = (float)WIN_WIDTH / WIN_HEIGHT;
	f[1] = tanf((data->cam->fov * 0.5f) * M_PI / 180.0f);
	f[2] = (2.0f * (x + 0.5f) / WIN_WIDTH - 1.0f) * f[0] * f[1];
	f[3] = (1.0f - 2.0f * (y + 0.5f) / WIN_HEIGHT) * f[1];
	data->cam->forw = normalize_vect(*data->cam->v);
	if (fabsf(data->cam->forw.x) == 0.0f && fabsf(data->cam->forw.z) == 0.0f)
		data->cam->right = (t_vector){1, 0, 0};
	else
		data->cam->right = normalize_vect(
				mult_vect((t_vector){0.0f, 1.0f, 0.0f}, data->cam->forw));
	data->cam->up = mult_vect(data->cam->forw, data->cam->right);
	v_cam = add_vector(add_vector(vector_scale(data->cam->right, f[2]),
				vector_scale(data->cam->up, f[3])), data->cam->forw);
	return (normalize_vect(v_cam));
}

void	ray_tracer(t_minirt *data)
{
	float	x;
	float	y;
	t_ray	ray;
	t_inter	*inter;

	x = -1.0f;
	while (++x < WIN_WIDTH)
	{
		y = -1.0f;
		while (++y < WIN_HEIGHT)
		{
			img_pix_put(data->img, x, y, encode_rgb((t_color){0, 0, 0}));
			ray.p = *data->cam->p;
			ray.v = make_vect_dir(data, x, y);
			inter = closest_inter(data, ray);
			if (inter)
			{
				inter->c = final_color(data, inter);
				img_pix_put(data->img, x, y, encode_rgb(inter->c));
				free(inter);
			}
		}
	}
}
