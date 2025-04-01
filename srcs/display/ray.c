/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:17:38 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/01 17:22:54 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	make_vect_dir(t_minirt *data, float x, float y)
{
	t_vector	v_dir;
	float		px;
	float		py;
	float		dist;
	int			max;

	px = x + 0.5 - WIN_WIDTH * 0.5;
	py = y + 0.5 - WIN_HEIGHT * 0.5;
	max = WIN_HEIGHT;
	if (WIN_WIDTH > WIN_HEIGHT)
		max = WIN_WIDTH;
	dist = max / (2 * tan((data->scene->cam->fov * 0.5) * M_PI / 180.0));
	v_dir = (t_vector){px, py, dist};
	return (normalize_vect(v_dir));
}

void	ray_tracer(t_minirt *data)
{
	float	x;
	float	y;
	t_ray	ray;
	t_inter	*inter;

	x = 0.0;
	while (x < WIN_WIDTH)
	{
		y = 0.0;
		while (y < WIN_HEIGHT)
		{
			ray.p = *data->scene->cam->p;
			//printf("ray.p=(%.1f,%.1f,%.1f)\n", ray.p.x, ray.p.y, ray.p.z);
			ray.v = make_vect_dir(data, x, y);
			//printf("rav.v=(%.1f,%.1f,%.1f)\n", ray.v.x, ray.v.y, ray.v.z);
			inter = closest_inter(data, ray);
			/*get closest intersection
			get color (with phong lights)
			add to image*/
			if (inter)
			{
				img_pix_put(data->img, x, y, encode_rgb(inter->c));
				free(inter);
			}
			y++;
		}
		x++;
	}
}
