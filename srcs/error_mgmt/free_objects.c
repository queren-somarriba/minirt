/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ojects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:21:24 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/21 17:37:42 by qsomarri         ###   ########.fr       */
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
	t_list	*node;

	node = *lst;
	while (node)
	{
		if (sizeof(node->content) == sizeof(t_sphere))
			free_sphere((t_sphere *)node->content);
		else if (sizeof(node->content) == sizeof(t_plane))
			free_plane((t_plane *)node->content);
		else if (sizeof(node->content) == sizeof(t_cylinder))
			free_cylinder((t_cylinder *)node->content);
		else
			printf("unfree node\n");
		node = node->next;
	}
	lst = NULL;
}
