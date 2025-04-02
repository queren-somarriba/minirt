/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:42:30 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/02 20:03:56 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*rt->=cy->center | v = ray.v | ro->=ray.p | s = cy->axis | r = cy->diam / 2*/

static float	quad_cylinder(t_cylinder *cy, t_ray ray, t_vector v)
{
	float 	q[3];
	t_vector v1;
	t_vector v2;
	float	res;

	v1 = mult_vect(mult_vect(*cy->axis, *cy->axis), ray.v);//va
	v2 = mult_vect(mult_vect(*cy->axis, *cy->axis), scalar_mult(v, -1));//rao
	q[0] = dot_product(v1, v1);
	q[1] = 2 * dot_product(v1, v2);
	q[2] = dot_product(v2, v2) - pow(cy->diam / 2, 2);
	res = quad(q[0], q[1], q[2]);
	return (res);
}

t_inter	*inter_cylinder(t_cylinder *cy, t_ray ray)
{
	t_inter	*intersection;
	t_vector v;
	float	res;

	v = (t_vector){cy->center->x - ray.p.x, cy->center->y - ray.p.y,
		cy->center->z - ray.p.z};
	res = quad_cylinder(cy, ray, v);
	if (res < 0.0)
		return (NULL);
	intersection = malloc(sizeof(t_inter));
	printf("res=%.1f\n", res);
	if (!intersection)
		return (perror("malloc"), NULL);
	intersection->p = (t_point){ray.p.x + ray.v.x * res,
		ray.p.y + ray.v.y * res, ray.p.z + ray.v.z * res};
	intersection->c = *cy->color;
	intersection->dist = res;
	return (intersection);
}

// bool	is_intersection_valid(t_ray ray, t_cylinder *cy, double t, double h)
// {
// 	t_vector	p_intersection;
// 	t_vector	d;
// 	float	m;

// 	p_intersection = add_vector((t_vector){ray.p.x, ray.p.y, ray.p.z}, scalar_mult(ray.v, t));
// 	d =(t_vector){p_intersection.x - cy->center->x,
// 			p_intersection.y - cy->center->y, p_intersection.z - cy->center->z};
// 	m = dot_product(d, *cy->axis);
// 	return (m >= 0 && m <= h);
// }

// float	quad_cylinder(t_ray ray, t_cylinder *cylinder, t_vector X)
// {
// 	float	quad[4];
// 	float	dist[2];

// 	quad[0] = dot_product(ray.v, ray.v) \
// 	- pow(dot_product(ray.v, *cylinder->axis), 2);
// 	quad[1] = 2 * (dot_product(ray.v, X) - \
// 	(dot_product(ray.v, *cylinder->axis) \
// 	* dot_product(X, *cylinder->axis)));
// 	quad[2] = dot_product(X, X) - \
// 	pow(dot_product(X, *cylinder->axis), 2) - pow(cylinder->diam / 2, 2);
// 	quad[3] = quad[1] * quad[1] - 4 * quad[0] * quad[2];
// 	if (quad[3] < 0)
// 	 	return (INFINITY);
// 	 dist[0] = (-quad[1] - sqrt(quad[3])) / (2 * quad[0]);
// 	 dist[1] = (-quad[1] + sqrt(quad[3])) / (2 * quad[0]);
// 	if (!is_intersection_valid(ray, cylinder, dist[0], cylinder->height))
// 		dist[0] = dist[1];
// 	if (!is_intersection_valid(ray, cylinder, dist[0], cylinder->height))
// 		return (INFINITY);
// 	if (dist[1] >= 0 && dist[1] < dist[0] && \
// 	is_intersection_valid(ray, cylinder, dist[1], cylinder->height))
// 		return(dist[1]);
// 	return (dist[0]);
// }

// t_inter	*inter_cylinder(t_cylinder *cylinder, t_ray ray)
// {
// 	t_inter	*inter;
// 	t_vector	v;
// 	float	res;

// 	v = (t_vector){ray.p.x - cylinder->center->x,
// 			ray.p.y - cylinder->center->y, ray.p.z - cylinder->center->z};
// 	res = quad_cylinder(ray, cylinder, v);
// 	if (res < 0.0)
// 		return (NULL);
// 	printf("res=%.1f\n", res);
// 	inter = malloc(sizeof(t_inter));
// 	if (!inter)
// 		return (perror("malloc"), NULL);
// 	inter->c = *cylinder->color;
// 	inter->p = (t_point){ray.p.x + ray.v.x * res,
// 		ray.p.y + ray.v.y * res, ray.p.z + ray.v.z * res};
// 	inter->dist = res;
// 	return (inter);
// }

// t_vector	cylinder_normal(t_vector P, t_cylinder *cylinder)
// {
// 	t_vector	cp;
// 	t_vector	norm_dir;
// 	t_vector	normal;
// 	double	m;
// 	double	length;

// 	cp = sub(P, cylinder->p);
// 	m = dot_product(cp, cylinder->norm_vec);
// 	norm_dir = sub(cp, sc_mult(cylinder->norm_vec, m));
// 	length = sqrt(dot_product(norm_dir, norm_dir));
// 	normal = new_v3d(norm_dir.x / length, norm_dir.y \
// 	/ length, norm_dir.z / length);
// 	return (normal);
// }