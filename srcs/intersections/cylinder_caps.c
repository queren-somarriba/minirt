/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:00:15 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/24 18:08:10 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter	*check_cap2(t_cylinder *cy, t_inter *inter, t_inter *inter2, t_vector c)
{
	float	dist;
	float	dist2;

	dist = vect_length(sub_vector(inter->p, *cy->center));
	dist2 = vect_length(sub_vector(inter2->p, c));
	if (dist > cy->diam / 2 && dist2 > cy->diam / 2)
		return (free(inter), free(inter2), NULL);
	if (dist > cy->diam / 2 || dist2 > cy->diam / 2)
	{
		if (dist > cy->diam / 2)
			return (free(inter), inter2);
		return (free(inter2), inter);
	}
	if (inter->dist < inter2->dist)
		return (free(inter2), inter);
	return (free(inter), inter2);
}

t_inter	*check_cap(t_cylinder *cy, t_inter *inter, t_inter *inter2, t_vector c)
{
	float	dist;
	float	dist2;

	if (inter)
		dist = vect_length(sub_vector(inter->p, *cy->center));
	if (inter2)
		dist2 = vect_length(sub_vector(inter2->p, c));
	if (!inter && !inter2)
		return (NULL);
	else if (!inter || !inter2)
	{
		if (inter && dist < cy->diam / 2)
			return (inter);
		else if (inter2 && dist2 < cy->diam / 2)
			return (inter2);
		if (inter)
			free(inter);
		else
			free(inter2);
		return (NULL);
	}
	return (check_cap2(cy, inter, inter2, c));
}

t_inter	*inter_caps(t_cylinder *cy, t_ray ray)
{
	t_vector	center;
	t_inter		*inter;
	t_inter		*inter2;
	t_plane		plane;

	plane = (t_plane){cy->center, cy->axis, cy->color};
	inter = inter_plane(&plane, ray);
	center = add_vector(*cy->center, vector_scale(*cy->axis, cy->height));
	plane = (t_plane){&center, cy->axis, cy->color};
	inter2 = inter_plane(&plane, ray);
	return (check_cap(cy, inter, inter2, center));
}
