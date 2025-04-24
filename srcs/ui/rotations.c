/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:55:51 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/24 15:11:43 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	rotate_around(t_vector *v, t_vector axis, float angle)
{
	t_vector	k;
	t_vector	cross;
	float		dot;

	k = normalize_vect(axis);
	cross = mult_vect(k, *v);
	dot = dot_product(k, *v);
	v->x = v->x * cosf(angle) + cross.x * sinf(angle)
		+ k.x * dot * (1 - cosf(angle));
	v->y = v->y * cosf(angle) + cross.y * sinf(angle)
		+ k.y * dot * (1 - cosf(angle));
	v->z = v->z * cosf(angle) + cross.z * sinf(angle)
		+ k.z * dot * (1 - cosf(angle));
}

static void	make_rotation(t_minirt *data, t_vector *v, int keysym)
{
	if (keysym == XK_1)
		rotate_around(v, data->cam->right, -M_PI / 36.0);
	else if (keysym == XK_2)
		rotate_around(v, data->cam->right, M_PI / 36.0);
	else if (keysym == XK_3)
		rotate_around(v, data->cam->up, -M_PI / 36.0);
	else if (keysym == XK_4)
		rotate_around(v, data->cam->up, M_PI / 36.0);
	else if (keysym == XK_5)
		rotate_around(v, data->cam->forw, -M_PI / 36.0);
	else if (keysym == XK_6)
		rotate_around(v, data->cam->forw, M_PI / 36.0);
}

int	rotation(t_minirt *data, int keysysm)
{
	t_objects	*node;

	if (!data)
		return (EXIT_SUCCESS);
	node = get_node(data, data->current_obj);
	if (!node)
		return (EXIT_SUCCESS);
	if (node->type == CAM)
		make_rotation(data, data->cam->v, keysysm);
	else if (node->type == PLANE)
		make_rotation(data, ((t_plane *)(node->obj))->axis, keysysm);
	else if (node->type == CYLINDER)
		make_rotation(data, ((t_cylinder *)(node->obj))->axis, keysysm);
	else if (printf("No rotation possible on current object!\n") < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
