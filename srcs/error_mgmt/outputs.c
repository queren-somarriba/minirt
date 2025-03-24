/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:52:15 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/24 18:03:53 by qsomarri         ###   ########.fr       */
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
	if (data->scene)
	{
		printf("SCENE:\n\n");
		if (data->scene->amb)
		{
			printf("amb ratio=%.1f\n", data->scene->amb->ratio);
			printf("amb color=[%d,%d,%d]\n", data->scene->amb->color->r,
				data->scene->amb->color->g, data->scene->amb->color->b);
		}
		if (data->scene->cam)
		{
			printf("cam fov=%d\n", data->scene->cam->fov);
			printf("cam point=[%.1f,%.1f,%.1f]\n", data->scene->cam->p->x,
				data->scene->cam->p->y, data->scene->cam->p->z);
			printf("cam vector=[%.1f,%.1f,%.1f]\n", data->scene->cam->v->x,
				data->scene->cam->v->y, data->scene->cam->v->z);
		}
		if (data->scene->light)
		{
			printf("light brightness=%.1f\n", data->scene->light->brightness);
			printf("light point=[%.1f,%.1f,%.1f]\n\n", data->scene->light->p->x,
				data->scene->light->p->y, data->scene->light->p->z);
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
		printf("OBJECTS:\n\n");
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
