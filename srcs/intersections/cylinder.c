/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:42:30 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/25 19:24:14 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	compute_coef(t_cylinder *cy, t_ray ray, float *quad, t_vector v)
{
	quad[0] = dot_product(ray.v, ray.v)
		- powf(dot_product(ray.v, *cy->axis), 2.0f);
	quad[1] = 2 * (dot_product(ray.v, v)
			- (dot_product(ray.v, *cy->axis)
				* dot_product(v, *cy->axis)));
	quad[2] = dot_product(v, v) - powf(dot_product(v, *cy->axis), 2.0f)
		- powf(cy->diam / 2.0f, 2.0f);
}

static t_vector	cylinder_normal(t_cylinder *cy, t_vector v)
{
	t_vector	normal;
	float		x;
	float		length;

	x = dot_product(v, *cy->axis);
	normal = sub_vector(v, vector_scale(*cy->axis, x));
	length = sqrtf(dot_product(normal, normal));
	normal = vector_scale(normal, 1.0f / length);
	return (normal);
}

static int	valid_inter(t_cylinder *cy, t_ray ray, float t, float h)
{
	t_vector	inter_point;
	t_vector	d;
	float		dist;

	inter_point = add_vector(ray.p, vector_scale(ray.v, t));
	d = sub_vector(inter_point, *cy->center);
	dist = dot_product(d, *cy->axis);
	if (dist >= 0.0f && dist <= h)
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
	dist[0] = (-quad[1] - sqrtf(delta)) / (2.0f * quad[0]);
	dist[1] = (-quad[1] + sqrtf(delta)) / (2.0f * quad[0]);
	if (valid_inter(cy, ray, dist[0], cy->height)
		&& valid_inter(cy, ray, dist[1], cy->height))
		return (INFINITY);
	if (valid_inter(cy, ray, dist[0], cy->height)
		|| valid_inter(cy, ray, dist[1], cy->height))
	{
		if (valid_inter(cy, ray, dist[0], cy->height))
			return (dist[1]);
		return (dist[0]);
	}
	if (dist[1] >= 0.0f && dist[1] < dist[0])
		return (dist[1]);
	return (dist[0]);
}

t_inter	*inter_cylinder(t_cylinder *cy, t_ray ray)
{
	t_inter		*inter;
	t_inter		*cap;
	float		t;
	float		quad[3];

	compute_coef(cy, ray, quad, sub_vector(ray.p, *cy->center));
	t = quad_cylinder(cy, ray, quad);
	cap = inter_caps(cy, ray);
	if (t == INFINITY)
		return (cap);
	if (cap && t > cap->dist)
		return (cap);
	inter = malloc(sizeof(t_inter));
	if (!inter)
	{
		if (cap)
			free(cap);
		return (perror("malloc"), NULL);
	}
	inter->p = add_vector(ray.p, vector_scale(ray.v, t));
	inter->c = *cy->color;
	inter->dist = t;
	inter->normal = cylinder_normal(cy, sub_vector(inter->p, *cy->center));
	return (free(cap), inter);
}
