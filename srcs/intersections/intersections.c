/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:14:42 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/31 18:46:25 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter	*closest_inter(t_minirt *data, t_ray ray)
{
	t_inter	*inter;
	t_inter	*closest;
	t_list	*current;

	current = *data->objects;
	closest = malloc(sizeof(t_inter));
	if (!closest)
		return (perror("malloc"), NULL);
	closest->dist = INFINITY;
	inter = NULL;
	while (current)
	{
		if (inter)
		{
			free(inter);
			inter = NULL;
		}
		if (((t_objects *)current->content)->type == SPHERE)
			inter = inter_sphere((t_sphere *)(((t_objects *)current->content)->obj), ray);
		if (((t_objects *)current->content)->type == PLANE)
			inter = inter_plane((t_plane *)(((t_objects *)current->content)->obj), ray);
		if (((t_objects *)current->content)->type == CYLINDER)
			inter = inter_cylinder((t_cylinder *)(((t_objects *)current->content)->obj), ray);
		if (inter && inter->dist < closest->dist)
		{
			free(closest);
			closest = inter;
		}
		current = current->next;
	}
	if (closest && closest->dist && closest->dist == INFINITY)
		return (free(closest), NULL);
	printf("dist=%.1f\n", closest->dist);
	return (closest);
}
