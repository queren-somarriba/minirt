/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:41:52 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/28 19:58:51 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	quad(double a, double b, double c)
{
	double	delta;
	double	t0;
	double	t1;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	t0 = (-b - sqrt(delta)) / (2 * a);
	t1 = (-b + sqrt(delta)) / (2 * a);
	if (t0 < 0)
		t0 = t1;
	if (t0 < 0)
		return (-1);
	else if (t1 >= 0 && t1 < t0)
		return (t1);
	else
		return (t0);
}


t_point	*inter_sphere(t_sphere sp, t_ray ray)
{
	t_vector	v;
	float	a;
	float	b;
	float	c;
	float	delta;
	float	res;

	v = (t_vector){sp.center->x  - ray.p.x, sp.center->y - ray.p.y, sp.center->z - ray.p.z};
	a = dot_product(ray.v, ray.v);
	b = 2.0 * dot_product(v, ray.v);
	c = dot_porduct(v, v) - sp.diam * sp.diam / 4;
	delta = b * b - 4.0 * a * c;
	if (delta < 0)
		return (NULL);	
}

// t_inter	*intersect_sphere(t_ray *ray, t_sphere *sphere)
// {
// 	t_inter	*inter;
// 	t_v3d	oc;
// 	double	t;

// 	inter = calloc_utils();
// 	oc = sub(ray->coord, sphere->coord);
// 	t = quad(dot_product(ray->v_dir, ray->v_dir), 2.0 * \
// 	dot_product(oc, ray->v_dir), dot_product(oc, oc) - sphere->r * sphere->r);
// 	if (t < 0)
// 	{
// 		inter->dist = INFINITY;
// 		return (inter);
// 	}
// 	inter->type = SPHERE;
// 	inter->obj.sp = *sphere;
// 	inter->dist = t;
// 	inter->point = add(ray->coord, sc_mult(ray->v_dir, t));
// 	inter->normal = normalize(sub(inter->point, sphere->coord));
// 	return (inter);
// }