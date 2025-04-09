/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:52:15 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/09 18:02:37 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	printerr(char *str)
{
	if (str)
		ft_putstr_fd(str, 2);
}

void	printerr2(char *str1, char *str2)
{
	printerr(str1);
	printerr(str2);
}

/*DEL*/

int	print_scene(t_minirt *data)
{
	if (data)
	{
		printf("SCENE:\n\n");
		if (data->amb)
		{
			printf("amb ratio=%.1f\n", data->amb->ratio);
			printf("amb color=[%d,%d,%d]\n", data->amb->color->r,
				data->amb->color->g, data->amb->color->b);
		}
		if (data->cam)
		{
			printf("cam fov=%d\n", data->cam->fov);
			printf("cam point=[%.1f,%.1f,%.1f]\n", data->cam->p->x,
				data->cam->p->y, data->cam->p->z);
			printf("cam vector=[%.1f,%.1f,%.1f]\n", data->cam->v->x,
				data->cam->v->y, data->cam->v->z);
		}
		if (data->light)
		{
			printf("light brightness=%.1f\n", data->light->brightness);
			printf("light point=[%.1f,%.1f,%.1f]\n\n", data->light->p->x,
				data->light->p->y, data->light->p->z);
		}
	}
	return (EXIT_SUCCESS);
}

int	print_objects(t_list **lst)
{
	t_list		*node;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;

	node = *lst;
	while (node)
	{
		if (((t_objects *)(node->content))->type == 0)
		{
			sp = ((t_sphere *)((t_objects *)node->content)->obj);
			printf("sphere-->\n");
			printf("center=[%.1f,%.1f,%.1f]\n", sp->center->x,
				sp->center->y, sp->center->z);
			printf("diameter=%.1f\n", sp->diam);
			printf("color=[%d,%d,%d]\n\n", sp->color->r,
				sp->color->g, sp->color->b);
		}
		if (((t_objects *)(node->content))->type == 1)
		{
			pl = ((t_plane *)((t_objects *)node->content)->obj);
			printf("plane-->\n");
			printf("point=[%.1f,%.1f,%.1f]\n", pl->point->x,
				pl->point->y, pl->point->z);
			printf("axis=[%.1f,%.1f,%.1f]\n", pl->axis->x,
				pl->axis->y, pl->axis->z);
			printf("color=[%d,%d,%d]\n\n", pl->color->r,
				pl->color->g, pl->color->b);
		}
		if (((t_objects *)(node->content))->type == 2)
		{
			cy = ((t_cylinder *)((t_objects *)node->content)->obj);
			printf("cylinder-->\n");
			printf("center=[%.1f,%.1f,%.1f]\n", cy->center->x,
				cy->center->y, cy->center->z);
			printf("axis=[%.1f,%.1f,%.1f]\n", cy->axis->x,
				cy->axis->y, cy->axis->z);
			printf("diameter=%.1f\n", cy->diam);
			printf("height=%.1f\n", cy->height);
			printf("color=[%d,%d,%d]\n\n", cy->color->r,
				cy->color->g, cy->color->b);
		}
		node = node->next;
	}
	return (EXIT_SUCCESS);
}
