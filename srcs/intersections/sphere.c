/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:41:52 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/25 19:22:24 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	quad(float a, float b, float c)
{
	float	delta;
	float	x;
	float	y;

	delta = b * b - 4.0f * a * c;
	if (delta < 0.0f || fabsf(a) < (float)1e-6)
		return (-1);
	x = (-b - sqrtf(delta)) / (2.0f * a);
	y = (-b + sqrtf(delta)) / (2.0f * a);
	if (x < 0.0f && y < 0.0f)
		return (-1);
	if (x > 0.0f && y > 0.0f)
		return (fminf(x, y));
	else if (x > 0.0f)
		return (x);
	else if (y > 0.0f)
		return (y);
	else
		return (-1.0f);
}

t_inter	*inter_sphere(t_sphere *sp, t_ray ray)
{
	t_inter		*inter;
	t_vector	v;
	float		t;

	v = sub_vector(ray.p, *sp->center);
	t = quad(dot_product(ray.v, ray.v), 2.0f * dot_product(v, ray.v),
			dot_product(v, v) - sp->diam * sp->diam / 4.0f);
	if (t < 0.0f)
		return (NULL);
	inter = malloc(sizeof(t_inter));
	if (!inter)
		return (perror("malloc"), NULL);
	inter->p = add_vector(ray.p, vector_scale(ray.v, t));
	inter->c = *sp->color;
	inter->dist = t;
	inter->normal = normalize_vect(sub_vector(inter->p, *sp->center));
	return (inter);
}
