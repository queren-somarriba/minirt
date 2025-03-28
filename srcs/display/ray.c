/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:17:38 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/28 18:40:20 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ray_tracer(t_minirt *data)
{
	double	x;
	double	y;
	t_ray	ray;

	x = 0.0;
	(void)data;
	while (x < WIN_WIDTH)
	{
		y = 0.0;
		while (y < WIN_HEIGHT)
		{
			ray.p = *data->scene->cam->p;
			ray.v = make_vect_dir(data, x, y);
			/*get closest intersection
			get color (with phong lights)
			add to image*/
			y++;
		}
		x++;
	}
}

t_vector	make_vect_dir(t_minirt *data, double x, double y)
{
	t_vector	v_dir;
	double		px;
	double		py;
	double		dist;
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
