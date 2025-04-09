/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:42:30 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/09 16:10:50 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	quad_cylinder(t_cylinder *cy, t_ray ray, t_vector v)
{
	t_vector	d_ortho;
	t_vector	v_ortho;
	float		q[3];

	d_ortho = sub_vector(ray.v,
			vector_scale(*cy->axis, dot_product(ray.v, *cy->axis)));
	v_ortho = sub_vector(v, vector_scale(*cy->axis, dot_product(v, *cy->axis)));
	q[0] = dot_product(d_ortho, d_ortho);
	q[1] = 2.0f * dot_product(d_ortho, v_ortho);
	q[2] = dot_product(v_ortho, v_ortho) - powf(cy->diam / 2, 2);
	return (quad(q[0], q[1], q[2]));
}

t_vector	normal_to_cylinder(t_cylinder *cy, t_inter inter)
{
	t_vector	cy_to_inter;
	t_vector	normal;
	float		a;

	cy_to_inter = (t_vector){inter.p.x - cy->center->x,
		inter.p.y - cy->center->y, inter.p.z - cy->center->z};
	a = dot_product(cy_to_inter, *cy->axis);
	normal = normalize_vect((t_vector){cy_to_inter.x - cy->axis->x * a,
			cy_to_inter.y - cy->axis->y * a, cy_to_inter.z - cy->axis->z * a});
	return (normal);
}

t_inter	*inter_cylinder(t_cylinder *cy, t_ray ray)
{
	t_inter		*intersection;
	t_vector	v;
	float		res;
	float		dist;

	v = (t_vector){cy->center->x - ray.p.x, cy->center->y - ray.p.y,
		cy->center->z - ray.p.z};
	res = quad_cylinder(cy, ray, v);
	if (res < 0.0)
		return (NULL);
	dist = dot_product((t_vector){ray.p.x + ray.v.x * res - cy->center->x,
			ray.p.y + ray.v.y * res - cy->center->y,
			ray.p.z + ray.v.z * res - cy->center->z}, *cy->axis);
	if (dist < -cy->height / 2 || dist > cy->height / 2)
		return (NULL);
	intersection = malloc(sizeof(t_inter));
	if (!intersection)
		return (perror("malloc"), NULL);
	intersection->p = (t_point){ray.p.x + ray.v.x * res,
		ray.p.y + ray.v.y * res, ray.p.z + ray.v.z * res};
	intersection->c = *cy->color;
	intersection->dist = res;
	intersection->normal = normal_to_cylinder(cy, *intersection);
	return (intersection);
}
