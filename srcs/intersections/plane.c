/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiech <jpiech@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:42:07 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/07 11:52:24 by jpiech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter	*inter_plane(t_plane *pl, t_ray ray)
{
	t_inter		*inter;
	t_vector	v;
	float		t;

	v = sub_vector(*pl->point, ray.p);
	t = dot_product(*pl->axis, ray.v);
	if (fabsf(t) < (float)1e-6)
		return (NULL);
	t = dot_product(*pl->axis, v) / t;
	if (t < (float)1e-6)
		return (NULL);
	inter = malloc(sizeof(t_inter));
	if (!inter)
		return (perror("malloc"), NULL);
	inter->p = add_vector(ray.p, vector_scale(ray.v, t));
	inter->c = *pl->color;
	inter->dist = t;
	inter->normal = normalize_vect(*pl->axis);
	if (dot_product(inter->normal, ray.v) > 0)
		inter->normal = vector_scale(inter->normal, -1);
	return (inter);
}
