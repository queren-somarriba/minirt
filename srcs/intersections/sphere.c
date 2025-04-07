/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:41:52 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/07 18:01:54 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	quad(float a, float b, float c)
{
	float	delta;
	float	x;
	float	y;

	delta = b * b - 4.0 * a * c;
	if (delta < 0 || fabs(a) < 1e-6)
		return (-1);
	x = (-b - sqrtf(delta)) / (2.0 * a);
	y = (-b + sqrtf(delta)) / (2.0 * a);
	if (x < 0 && y < 0)
		return (-1);
	if (x > 0.0 && y > 0.0)
		return (fminf(x, y));
	else if (x > 0.0)
		return (x);
	else if (y > 0.0)
		return (y);
	else
		return (-1);
}

t_inter	*inter_sphere(t_sphere *sp, t_ray ray)
{
	t_inter		*intersection;
	t_vector	v;
	float		res;

	v = (t_vector){sp->center->x - ray.p.x,
		sp->center->y - ray.p.y, sp->center->z - ray.p.z};
	res = quad(dot_product(ray.v, ray.v), 2.0 * dot_product(v, ray.v),
			dot_product(v, v) - sp->diam * sp->diam / 4);
	if (res < 0.0)
		return (NULL);
	intersection = malloc(sizeof(t_inter));
	if (!intersection)
		return (perror("malloc"), NULL);
	intersection->p = (t_point){ray.p.x + v.x * res,
		ray.p.y + v.y * res, ray.p.z + v.z * res};
	intersection->c = *sp->color;
	intersection->dist = res;
	intersection->normal = normalize_vect((t_vector){
			intersection->p.x - sp->center->x,
			intersection->p.y - sp->center->y,
			intersection->p.z - sp->center->z});
	intersection->obj_index = sp->index;
	return (intersection);
}
