/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:42:30 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/11 18:42:34 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	cylinder_normal(t_cylinder *cy, t_vector v)
{
	t_vector	normal;
	float		x;
	float		length;

	x = dot_product(v, *cy->axis);
	normal = sub_vector(v, vector_scale(*cy->axis, x));
	length = sqrt(dot_product(normal, normal));
	normal = vector_scale(normal, 1 / length);
	return (normal);
}

static int	valid_inter(t_cylinder *cy, t_ray ray, float t, float h)
{
	t_vector	p_inter;
	t_vector	d;
	float		m;

	p_inter = add_vector(ray.p, vector_scale(ray.v, t));
	d = sub_vector(p_inter, *cy->center);
	m = dot_product(d, *cy->axis);
	if (m >= 0 && m <= h)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static float	quad_cylinder(t_cylinder *cy, t_ray ray, float *quad)
{
	float	delta;
	float	dist[2];

	delta = quad[1] * quad[1] - 4 * quad[0] * quad[2];
	if (delta < 0)
		return (INFINITY);
	dist[0] = (-quad[1] - sqrtf(delta)) / (2 * quad[0]);
	dist[1] = (-quad[1] + sqrtf(delta)) / (2 * quad[0]);
	if (valid_inter(cy, ray, dist[0], cy->height))
		dist[0] = dist[1];
	if (valid_inter(cy, ray, dist[0], cy->height))
		return (INFINITY);
	if (dist[1] >= 0 && dist[1] < dist[0]
		&& !valid_inter(cy, ray, dist[1], cy->height))
		return (dist[1]);
	return (dist[0]);
}

t_inter	*inter_cylinder(t_cylinder *cy, t_ray ray)
{
	t_inter		*inter;
	t_vector	v;
	float		t;
	float		quad[3];

	v = sub_vector(ray.p, *cy->center);
	quad[0] = dot_product(ray.v, ray.v)
		- powf(dot_product(ray.v, *cy->axis), 2);
	quad[1] = 2 * (dot_product(ray.v, v)
			- (dot_product(ray.v, *cy->axis)
				* dot_product(v, *cy->axis)));
	quad[2] = dot_product(v, v) - powf(dot_product(v, *cy->axis), 2)
		- powf(cy->diam / 2, 2);
	t = quad_cylinder(cy, ray, quad);
	if (t == INFINITY)
		return (NULL);
	inter = malloc(sizeof(t_inter));
	if (!inter)
		return (perror("malloc"), NULL);
	inter->p = add_vector(ray.p, vector_scale(ray.v, t));
	inter->c = *cy->color;
	inter->dist = t;
	inter->normal = cylinder_normal(cy, sub_vector(inter->p, *cy->center));
	return (inter);
}
