/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_and_translate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:10 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/25 19:17:55 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	resize(t_minirt *data, int keysysm)
{
	t_objects	*node;

	node = get_node(data, data->current_obj);
	if (node->type == SPHERE)
	{
		if (keysysm == XK_Up && ((t_sphere *)node->obj)->diam < 100.0f)
			((t_sphere *)node->obj)->diam += 1;
		if (keysysm == XK_Down && ((t_sphere *)node->obj)->diam > 0.0f)
			((t_sphere *)node->obj)->diam -= 1;
	}
	else if (node->type == CYLINDER)
	{
		if (keysysm == XK_Up && ((t_cylinder *)node->obj)->diam < 100.0f)
			((t_cylinder *)node->obj)->diam += 1;
		if (keysysm == XK_Down && ((t_cylinder *)node->obj)->diam > 0.0f)
			((t_cylinder *)node->obj)->diam -= 1;
		if (keysysm == XK_Right && ((t_cylinder *)node->obj)->height < 100.0f)
			((t_cylinder *)node->obj)->height += 1;
		if (keysysm == XK_Left && ((t_cylinder *)node->obj)->height > 0.0f)
			((t_cylinder *)node->obj)->height -= 1;
	}
	else
		return (printf("No resize posible on current object!\n"), EXIT_FAILURE);
	ray_tracer(data);
	return (EXIT_SUCCESS);
}

static void	compute_translation(t_minirt *data, t_vector *pos, int keysym)
{
	if (keysym == XK_w)
		*pos = add_vector(*pos, vector_scale(data->cam->forw, 1.0f));
	else if (keysym == XK_s)
		*pos = add_vector(*pos, vector_scale(data->cam->forw, -1.0f));
	else if (keysym == XK_a)
		*pos = add_vector(*pos, vector_scale(data->cam->right, -1.0f));
	else if (keysym == XK_d)
		*pos = add_vector(*pos, vector_scale(data->cam->right, 1.0f));
	else if (keysym == XK_e)
		*pos = add_vector(*pos, vector_scale(data->cam->up, 1.0f));
	else if (keysym == XK_q)
		*pos = add_vector(*pos, vector_scale(data->cam->up, -1.0f));
	ray_tracer(data);
}

int	translation(t_minirt *data, int keysysm)
{
	t_objects	*node;

	if (!data)
		return (EXIT_SUCCESS);
	node = get_node(data, data->current_obj);
	if (!node)
		return (EXIT_SUCCESS);
	if (node->type == CAM)
		compute_translation(data, data->cam->p, keysysm);
	else if (node->type == LIGHT)
		compute_translation(data, data->light->p, keysysm);
	else if (node->type == SPHERE)
		compute_translation(data, ((t_sphere *)(node->obj))->center, keysysm);
	else if (node->type == PLANE)
		compute_translation(data, ((t_plane *)(node->obj))->point, keysysm);
	else if (node->type == CYLINDER)
		compute_translation(data, ((t_cylinder *)(node->obj))->center, keysysm);
	else if (printf("No translation possible on current object!\n") < 0)
		return (EXIT_FAILURE);
	return (printf(EXIT_SUCCESS));
}
