/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:42:30 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/10 19:26:31 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// bool	is_inter_valid(t_ray *ray, t_cylinder *cy, double t, double h)
// {
// 	t_vector	p_inter;
// 	t_vector	d;
// 	double		m;

// 	p_inter = add_vector(ray->p, vector_scale(ray->v, t));
// 	d = sub_vector(p_inter, *cy->center);
// 	m = dot_product(d, *cy->axis);
// 	return (m >= 0 && m <= h);
// }

// int	quad_cylinder(t_ray *ray, t_inter *inter, t_cylinder *cylinder, t_vector X)
// {
// 	double	quad[4];
// 	double	dist[2];

// 	quad[0] = dot_product(ray->v, ray->v)
// 		- powf(dot_product(ray->v, *cylinder->axis), 2);
// 	quad[1] = 2 * (dot_product(ray->v, X)
// 			- (dot_product(ray->v, *cylinder->axis)
// 				* dot_product(X, *cylinder->axis)));
// 	quad[2] = dot_product(X, X) - powf(dot_product(X, *cylinder->axis), 2)
// 		- powf(cylinder->diam / 2, 2);
// 	quad[3] = quad[1] * quad[1] - 4 * quad[0] * quad[2];
// 	if (quad[3] < 0)
// 		return (inter->dist = INFINITY, 0);
// 	dist[0] = (-quad[1] - sqrtf(quad[3])) / (2 * quad[0]);
// 	dist[1] = (-quad[1] + sqrtf(quad[3])) / (2 * quad[0]);
// 	if (!is_inter_valid(ray, cylinder, dist[0], cylinder->height))
// 		dist[0] = dist[1];
// 	if (!is_inter_valid(ray, cylinder, dist[0], cylinder->height))
// 		return (inter->dist = INFINITY, 0);
// 	if (dist[1] >= 0 && dist[1] < dist[0]
// 		&& is_inter_valid(ray, cylinder, dist[1], cylinder->height))
// 		inter->dist = dist[1];
// 	else
// 		inter->dist = dist[0];
// 	return (1);
// }

// t_vector	cylinder_normal(t_vector P, t_cylinder *cylinder)
// {
// 	t_vector	cp;
// 	t_vector	norm_dir;
// 	t_vector	normal;
// 	double		m;
// 	double		length;

// 	cp = sub_vector(P, *cylinder->center);
// 	m = dot_product(cp, *cylinder->axis);
// 	norm_dir = sub_vector(cp, vector_scale(*cylinder->axis, m));
// 	length = sqrt(dot_product(norm_dir, norm_dir));
// 	normal = vector_scale(norm_dir, 1 / length);
// 	return (normal);
// }

// t_inter	*inter_cylinder(t_cylinder *cy, t_ray ray)
// {
// 	t_inter		*inter;
// 	t_vector	v;
// 	// float		t;

// 	v = sub_vector(ray.p, *cy->center);
// 	inter = malloc(sizeof(t_inter));
// 	if (!inter)
// 		return (perror("malloc"), NULL);
// 	if (!quad_cylinder(&ray, inter, cy, v))
// 		return (NULL);
// 	inter->p = add_vector(ray.p, vector_scale(ray.v, inter->dist));
// 	inter->c = *cy->color;
// 	// inter->dist = t;
// 	inter->normal = normalize_vect(sub_vector(inter->p, *cy->center));
// 	return (inter);
// }

bool	is_inter_valid(t_ray *ray, t_cylinder *cy, double t, double h)
{
	t_vector	p_inter;
	t_vector	d;
	double		m;

	p_inter = add_vector(ray->p, vector_scale(ray->v, t));
	d = sub_vector(p_inter, *cy->center);
	m = dot_product(d, *cy->axis);
	return (m >= 0 && m <= h);
}

int	quad_cylinder(t_ray *ray, t_inter *inter, t_cylinder *cy, t_vector v)
{
	double	quad[4];
	double	dist[2];

	quad[0] = dot_product(ray->v, ray->v)
		- powf(dot_product(ray->v, *cy->axis), 2);
	quad[1] = 2 * (dot_product(ray->v, v)
			- (dot_product(ray->v, *cy->axis)
				* dot_product(v, *cy->axis)));
	quad[2] = dot_product(v, v) - powf(dot_product(v, *cy->axis), 2)
		- powf(cy->diam / 2, 2);
	quad[3] = quad[1] * quad[1] - 4 * quad[0] * quad[2];
	if (quad[3] < 0)
		return (inter->dist = INFINITY, 0);
	dist[0] = (-quad[1] - sqrtf(quad[3])) / (2 * quad[0]);
	dist[1] = (-quad[1] + sqrtf(quad[3])) / (2 * quad[0]);
	if (!is_inter_valid(ray, cy, dist[0], cy->height))
		dist[0] = dist[1];
	if (!is_inter_valid(ray, cy, dist[0], cy->height))
		return (inter->dist = INFINITY, 0);
	if (dist[1] >= 0 && dist[1] < dist[0]
		&& is_inter_valid(ray, cy, dist[1], cy->height))
		inter->dist = dist[1];
	else
		inter->dist = dist[0];
	return (1);
}

t_vector	cylinder_normal(t_vector v, t_cylinder *cy)
{
	t_vector	cp;
	t_vector	norm_dir;
	t_vector	normal;
	double		m;
	double		length;

	cp = sub_vector(v, *cy->center);
	m = dot_product(cp, *cy->axis);
	norm_dir = sub_vector(cp, vector_scale(*cy->axis, m));
	length = sqrt(dot_product(norm_dir, norm_dir));
	normal = vector_scale(norm_dir, 1 / length);
	return (normal);
}

t_inter	*inter_cylinder(t_cylinder *cy, t_ray ray)
{
	t_inter		*inter;
	t_vector	v;
	// float		t;

	v = sub_vector(ray.p, *cy->center);
	inter = malloc(sizeof(t_inter));
	if (!inter)
		return (perror("malloc"), NULL);
	if (!quad_cylinder(&ray, inter, cy, v))
		return (NULL);
	inter->p = add_vector(ray.p, vector_scale(ray.v, inter->dist));
	inter->c = *cy->color;
	// inter->dist = t;
	inter->normal = normalize_vect(sub_vector(inter->p, *cy->center));
	return (inter);
}