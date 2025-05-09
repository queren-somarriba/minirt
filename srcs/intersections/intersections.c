/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:14:42 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/25 17:30:18 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_inter	*find_inter(t_list *node, t_ray ray)
{
	t_inter	*inter;

	inter = NULL;
	if (((t_objects *)node->content)->type == SPHERE)
		inter = inter_sphere(
				(t_sphere *)(((t_objects *)node->content)->obj), ray);
	if (((t_objects *)node->content)->type == PLANE)
		inter = inter_plane(
				(t_plane *)(((t_objects *)node->content)->obj), ray);
	if (((t_objects *)node->content)->type == CYLINDER)
		inter = inter_cylinder(
				(t_cylinder *)(((t_objects *)node->content)->obj), ray);
	if (inter)
			inter->obj_index = ((t_objects *)(node->content))->index;
	return (inter);
}

static t_inter	*free_and_assign(t_inter *inter, t_inter *new)
{
	if (inter)
		free(inter);
	inter = new;
	return (inter);
}

t_inter	*closest_inter(t_minirt *data, t_ray ray)
{
	t_inter	*closest;
	t_inter	*inter;
	t_list	*node;

	node = *data->objects;
	inter = NULL;
	closest = malloc(sizeof(t_inter));
	if (!closest)
		return (perror("malloc"), NULL);
	closest->dist = INFINITY;
	while (node)
	{
		inter = find_inter(node, ray);
		if (inter && inter->dist < closest->dist)
			closest = free_and_assign(closest, inter);
		else
			inter = free_and_assign(inter, NULL);
		node = node->next;
	}
	if (closest && closest->dist && closest->dist == INFINITY)
		return (free(closest), NULL);
	return (closest);
}

t_inter	*closest_inter_shadow(t_minirt *data, t_ray ray, int index)
{
	t_inter	*closest;
	t_inter	*inter;
	t_list	*node;

	node = *data->objects;
	inter = NULL;
	closest = malloc(sizeof(t_inter));
	if (!closest)
		return (perror("malloc"), NULL);
	closest->dist = INFINITY;
	while (node)
	{
		if (((t_objects *)node->content)->index != index)
		{
			inter = find_inter(node, ray);
			if (inter && inter->dist < closest->dist)
				closest = free_and_assign(closest, inter);
			else
				inter = free_and_assign(inter, NULL);
		}
		node = node->next;
	}
	if (closest && closest->dist && closest->dist == INFINITY)
		return (free(closest), NULL);
	return (closest);
}
