/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:10 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/23 19:41:51 by qsomarri         ###   ########.fr       */
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
		if (keysysm == XK_Up && ((t_sphere *)node->obj)->diam < 10)
			((t_sphere *)node->obj)->diam += 1;
		if (keysysm == XK_Down && ((t_sphere *)node->obj)->diam > 1)
			((t_sphere *)node->obj)->diam -= 1;
	}
	else if (node->type == CYLINDER)
	{
		if (keysysm == XK_Up && ((t_cylinder *)node->obj)->diam < 10)
			((t_cylinder *)node->obj)->diam += 1;
		if (keysysm == XK_Down && ((t_cylinder *)node->obj)->diam > 1)
			((t_cylinder *)node->obj)->diam -= 1;
		if (keysysm == XK_Right && ((t_cylinder *)node->obj)->height < 50)
			((t_cylinder *)node->obj)->height += 1;
		if (keysysm == XK_Left && ((t_cylinder *)node->obj)->height > 1)
			((t_cylinder *)node->obj)->height -= 1;
	}
	else if (printf("No resize posible on current object!\n") < 0)
		return (EXIT_FAILURE);
	return (printf("resize\n"), EXIT_SUCCESS);
}

// void	make_translation(t_vector *v, int keysysm)
// {
// 	if (!v)
// 		return ;
// 	else if (keysysm == XK_i)
// 		v->x += 1;
// 	else if (keysysm == XK_j)
// 		v->y += 1;
// 	else if (keysysm == XK_l)
// 		v->z += 1;
// 	else if (keysysm == XK_w)
// 		v->x -= 1;
// 	else if (keysysm == XK_a)
// 		v->y -= 1;
// 	else if (keysysm == XK_d)
// 		v->z -= 1;
// }

void	make_translation(t_minirt *data, t_vector *pos, int keysym)
{
	t_vector forw = normalize_vect(*data->cam->v);
	t_vector right;
	t_vector up;

	if (fabsf(forw.x) == 0 && fabsf(forw.z) == 0)
		right = (t_vector){1, 0, 0};
	else
		right = normalize_vect(mult_vect((t_vector){0, 1, 0}, forw));
	up = mult_vect(forw, right);

	if (keysym == XK_w)
		*pos = add_vector(*pos, vector_scale(forw, 1));
	else if (keysym == XK_s)
		*pos = add_vector(*pos, vector_scale(forw, -1));
	else if (keysym == XK_a)
		*pos = add_vector(*pos, vector_scale(right, -1));
	else if (keysym == XK_d)
		*pos = add_vector(*pos, vector_scale(right, 1));
	else if (keysym == XK_e)
		*pos = add_vector(*pos, vector_scale(up, 1));
	else if (keysym == XK_q)
		*pos = add_vector(*pos, vector_scale(up, -1));
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
		make_translation(data, data->cam->p, keysysm);
	else if (node->type == LIGHT)
		make_translation(data, data->light->p, keysysm);
	else if (node->type == SPHERE)
		make_translation(data, ((t_sphere *)(node->obj))->center, keysysm);
	else if (node->type == PLANE)
		make_translation(data, ((t_plane *)(node->obj))->point, keysysm);
	else if (node->type == CYLINDER)
		make_translation(data, ((t_cylinder *)(node->obj))->center, keysysm);
	else if (printf("No translation possible on current object!\n") < 0)
		return (EXIT_FAILURE);
	return (printf("translate\n"), EXIT_SUCCESS);
}

// void	make_rotation(t_vector *v, int keysym)
// {
// 	if (!v)
// 		return ;
// 	if (keysym == XK_1)
// 		rotate_x(v, -M_PI / 36.0);
// 	else if (keysym == XK_2)
// 		rotate_x(v, M_PI / 36.0);
// 	else if (keysym == XK_3)
// 		rotate_y(v, -M_PI / 36.0);
// 	else if (keysym == XK_4)
// 		rotate_y(v, M_PI / 36.0);
// 	else if (keysym == XK_5)
// 		rotate_z(v, -M_PI / 36.0);
// 	else if (keysym == XK_6)
// 		rotate_z(v, M_PI / 36.0);
// }

void	rotate_around(t_vector *v, t_vector axis, float angle)
{
	t_vector	k = normalize_vect(axis);
	t_vector	v_orig = *v;
	t_vector	cross;
	float		cos_theta = cosf(angle);
	float		sin_theta = sinf(angle);
	float		dot = dot_product(k, v_orig);

	// k × v
	cross.x = k.y * v_orig.z - k.z * v_orig.y;
	cross.y = k.z * v_orig.x - k.x * v_orig.z;
	cross.z = k.x * v_orig.y - k.y * v_orig.x;

	// Rodrigues formula
	v->x = v_orig.x * cos_theta + cross.x * sin_theta + k.x * dot * (1 - cos_theta);
	v->y = v_orig.y * cos_theta + cross.y * sin_theta + k.y * dot * (1 - cos_theta);
	v->z = v_orig.z * cos_theta + cross.z * sin_theta + k.z * dot * (1 - cos_theta);
}


void	make_rotation(t_minirt *data, t_vector *v, int keysym)
{
	t_vector forw = normalize_vect(*data->cam->v);
	t_vector right, up;

	if (fabsf(forw.x) == 0 && fabsf(forw.z) == 0)
		right = (t_vector){1, 0, 0};
	else
		right = normalize_vect(mult_vect((t_vector){0, 1, 0}, forw));
	up = mult_vect(forw, right);

	if (keysym == XK_1)
		rotate_around(v, right, -M_PI / 36.0);
	else if (keysym == XK_2)
		rotate_around(v, right, M_PI / 36.0);
	else if (keysym == XK_3)
		rotate_around(v, up, -M_PI / 36.0);
	else if (keysym == XK_4)
		rotate_around(v, up, M_PI / 36.0);
	else if (keysym == XK_5)
		rotate_around(v, forw, -M_PI / 36.0);
	else if (keysym == XK_6)
		rotate_around(v, forw, M_PI / 36.0);
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
		make_rotation(data, data->cam->v, keysysm);
	else if (node->type == PLANE)
		make_rotation(data, ((t_plane *)(node->obj))->axis, keysysm);
	else if (node->type == CYLINDER)
		make_rotation(data, ((t_cylinder *)(node->obj))->axis, keysysm);
	else if (printf("No rotation possible on current object!\n") < 0)
		return (EXIT_FAILURE);
	return (printf("rotate\n"), EXIT_SUCCESS);
}
