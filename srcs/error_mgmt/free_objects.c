/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:21:24 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/24 17:48:46 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_sphere(t_sphere *sp)
{
	if (sp)
	{
		if (sp->center)
		{
			free(sp->center);
			sp->center = NULL;
		}
		if (sp->color)
		{
			free(sp->color);
			sp->color = NULL;
		}
		free(sp);
		sp = NULL;
	}
}

void	free_plane(t_plane *pl)
{
	if (pl)
	{
		if (pl->point)
		{
			free(pl->point);
			pl->point = NULL;
		}
		if (pl->axis)
		{
			free(pl->axis);
			pl->axis = NULL;
		}
		if (pl->color)
		{
			free(pl->color);
			pl->color = NULL;
		}
		free(pl);
		pl = NULL;
	}
}

void	free_cylinder(t_cylinder *cy)
{
	if (cy)
	{
		if (cy->center)
		{
			free(cy->center);
			cy->center = NULL;
		}
		if (cy->axis)
		{
			free(cy->axis);
			cy->axis = NULL;
		}
		if (cy->color)
		{
			free(cy->color);
			cy->color = NULL;
		}
		free(cy);
		cy = NULL;
	}
}

void	free_objects_lst(t_list **lst)
{
	t_list		*node;
	t_list		*tmp;
	t_objects	*obj_node;

	node = *lst;
	while (node)
	{
		obj_node = (t_objects *)(node->content);
		if (obj_node->type == 0)
			free_sphere((t_sphere *)obj_node->obj);
		else if (obj_node->type == 1)
			free_plane((t_plane *)obj_node->obj);
		else if (obj_node->type == 2)
			free_cylinder((t_cylinder *)obj_node->obj);
		else
			printf("unfree node\n");
		free(obj_node);
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(lst);
	lst = NULL;
}
