/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiech <jpiech@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:52:44 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/06 11:43:16 by jpiech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	add_node_object(t_minirt *data, void *obj, t_obj_id id)
{
	t_list		*new;
	t_objects	*obj_node;

	obj_node = malloc(sizeof(t_objects));
	if (!obj_node)
		return (perror("malloc"), EXIT_FAILURE);
	obj_node->obj = obj;
	obj_node->type = id;
	obj_node->index = ft_lstsize(*data->objects);
	new = ft_lstnew(obj_node);
	if (!new)
		return (perror("malloc"), EXIT_FAILURE);
	ft_lstadd_back(data->objects, new);
	return (EXIT_SUCCESS);
}

int	pars_sphere(t_minirt *data, char **arr, int count)
{
	t_sphere	*sp;

	if (arr_size(arr) != 4 || check_nptr(arr))
		return (printerr_line(count, SP_FORMAT), EXIT_FAILURE);
	sp = ft_calloc(1, sizeof(t_sphere));
	if (!sp)
		return (perror("malloc"), EXIT_FAILURE);
	sp->diam = ft_atof(arr[2]);
	if (sp->diam <= 0)
		return (free(sp), printerr_line(count, DIAM_ERROR), EXIT_FAILURE);
	sp->center = get_point(arr[1], count);
	if (!sp->center)
		return (free(sp), EXIT_FAILURE);
	sp->color = get_color(arr[3], count);
	if (!sp->color)
		return (free_sphere(sp), EXIT_FAILURE);
	if (add_node_object(data, sp, SPHERE))
		return (free_sphere(sp), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	pars_plane(t_minirt *data, char **arr, int count)
{
	t_plane	*pl;

	if (arr_size(arr) != 4 || check_nptr(arr))
		return (printerr_line(count, PL_FORMAT), EXIT_FAILURE);
	pl = ft_calloc(1, sizeof(t_plane));
	if (!pl)
		return (perror("malloc"), EXIT_FAILURE);
	pl->point = get_point(arr[1], count);
	if (!pl->point)
		return (free(pl), EXIT_FAILURE);
	pl->axis = get_vector(arr[2], count);
	if (!pl->axis)
		return (free_plane(pl), EXIT_FAILURE);
	pl->color = get_color(arr[3], count);
	if (!pl->color)
		return (free_plane(pl), EXIT_FAILURE);
	if (add_node_object(data, pl, PLANE))
		return (free_plane(pl), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	pars_cylinder2(t_minirt *data, char **arr,
			t_cylinder *cy, int count)
{
	cy->color = get_color(arr[5], count);
	if (!cy->color)
		return (free_cylinder(cy), EXIT_FAILURE);
	if (add_node_object(data, cy, CYLINDER))
		return (free_cylinder(cy), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	pars_cylindre(t_minirt *data, char **arr, int count)
{
	t_cylinder	*cy;

	if (arr_size(arr) != 6 || check_nptr(arr))
		return (printerr_line(count, CY_FORMAT), EXIT_FAILURE);
	cy = ft_calloc(1, sizeof(t_cylinder));
	if (!cy)
		return (perror("malloc"), EXIT_FAILURE);
	cy->diam = ft_atof(arr[3]);
	if (cy->diam < 0.0f)
		return (free(cy), printerr_line(count, DIAM_ERROR), EXIT_FAILURE);
	cy->height = ft_atof(arr[4]);
	if (cy->height < 0.0f)
		return (free(cy), printerr_line(count, HEIGHT_ERROR), EXIT_FAILURE);
	cy->center = get_point(arr[1], count);
	if (!cy->center)
		return (free_cylinder(cy), EXIT_FAILURE);
	cy->axis = get_vector(arr[2], count);
	if (!cy->axis)
		return (free_cylinder(cy), EXIT_FAILURE);
	if (pars_cylinder2(data, arr, cy, count))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
