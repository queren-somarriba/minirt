/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:10 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/11 19:21:20 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	resize(t_minirt *data, int keysysm)
{
	t_objects	*node;

	node = get_node(data, data->current_obj);
	print_object(node);
	if (node->type == SPHERE)
	{
		if (keysysm == XK_Up)
			((t_sphere *)node->obj)->diam += 10;
		if (keysysm == XK_Down)
			((t_sphere *)node->obj)->diam -= 10;
	}
	else if (node->type == CYLINDER)
	{
		if (keysysm == XK_Up)
			((t_cylinder *)node->obj)->diam += 10;
		if (keysysm == XK_Down)
			((t_cylinder *)node->obj)->diam -= 10;
		if (keysysm == XK_Right)
			((t_cylinder *)node->obj)->height += 10;
		if (keysysm == XK_Left)
			((t_cylinder *)node->obj)->height -= 10;
	}
	else if (printf("No resize posible on current object!\n") < 0)
		return (EXIT_FAILURE);
	return (printf("resize\n"), EXIT_SUCCESS);
}

void	make_translation(t_vector *v, int keysysm)
{
	if (!v)
		return ;
	else if (keysysm == XK_i)
		v->x += 1;
	else if (keysysm == XK_j)
		v->y += 1;
	else if (keysysm == XK_l)
		v->z += 1;
	else if (keysysm == XK_w)
		v->x -= 1;
	else if (keysysm == XK_a)
		v->y -= 1;
	else if (keysysm == XK_d)
		v->z -= 1;
}

int	translation(t_minirt *data, int keysysm)
{
	t_objects	*node;

	if (!data)
		return (EXIT_SUCCESS);
	node = get_node(data, data->current_obj);
	print_object(node);
	if (!node)
		return (EXIT_SUCCESS);
	if (node->type == CAM)
		make_translation(data->cam->p, keysysm);
	else if (node->type == LIGHT)
		make_translation(data->light->p, keysysm);
	else if (node->type == SPHERE)
		make_translation(((t_sphere *)(node->obj))->center, keysysm);
	else if (node->type == PLANE)
		make_translation(((t_plane *)(node->obj))->point, keysysm);
	else if (node->type == CYLINDER)
		make_translation(((t_cylinder *)(node->obj))->center, keysysm);
	else if (printf("No translation possible on current object!\n") < 0)
		return (EXIT_FAILURE);
	return (printf("translate\n"), EXIT_SUCCESS);
}

void	make_rotation(t_vector *v, int keysym)
{
	if (!v)
		return ;
	if (keysym == XK_1)
		rotate_x(v, -M_PI / 36.0);
	else if (keysym == XK_2)
		rotate_x(v, M_PI / 36.0);
	else if (keysym == XK_3)
		rotate_y(v, -M_PI / 36.0);
	else if (keysym == XK_4)
		rotate_y(v, M_PI / 36.0);
	else if (keysym == XK_5)
		rotate_z(v, -M_PI / 36.0);
	else if (keysym == XK_6)
		rotate_z(v, M_PI / 36.0);
}

int	rotation(t_minirt *data, int keysysm)
{
	t_objects	*node;

	if (!data)
		return (EXIT_SUCCESS);
	node = get_node(data, data->current_obj);
	print_object(node);
	if (!node)
		return (EXIT_SUCCESS);
	if (node->type == CAM)
		make_rotation(data->cam->v, keysysm);
	else if (node->type == PLANE)
		make_rotation(((t_plane *)(node->obj))->axis, keysysm);
	else if (node->type == CYLINDER)
		make_rotation(((t_cylinder *)(node->obj))->axis, keysysm);
	else if (printf("No rotation possible on current object!\n") < 0)
		return (EXIT_FAILURE);
	return (printf("rotate\n"), EXIT_SUCCESS);
}
