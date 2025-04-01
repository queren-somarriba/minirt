/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:42:07 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/01 19:20:37 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter	*inter_plane(t_plane *pl, t_ray ray)
{
	t_inter		*intersection;
	t_vector	v;
	float		res;

	v = (t_vector){ray.p.x - pl->point->x, ray.p.y - pl->point->y,
		ray.p.z - pl->point->z};
	res = dot_product(*pl->axis, v) / dot_product(*pl->axis, ray.v);
	if (res < 0.0)
		return (NULL);
	intersection = malloc(sizeof(t_inter));
	if (!intersection)
		return (perror("malloc"), NULL);
	intersection->p = (t_point){ray.p.x + v.x * res,
		ray.p.y + v.y * res, ray.p.z + v.z * res};
	intersection->c = *pl->color;
	intersection->dist = res;
	return (intersection);
}
