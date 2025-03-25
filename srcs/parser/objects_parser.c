/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:52:44 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/25 15:15:17 by qsomarri         ###   ########.fr       */
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
	new = ft_lstnew(obj_node);
	if (!new)
		return (perror("malloc"), EXIT_FAILURE);
	ft_lstadd_back(data->objects, new);
	return (EXIT_SUCCESS);
}

int	pars_sphere(t_minirt *data, char **arr)
{
	t_sphere	*sp;

	if (arr_size(arr) != 4 || check_nptr(arr))
		return (printerr(SP_FORMAT), EXIT_FAILURE);
	sp = ft_calloc(1, sizeof(t_sphere));
	if (!sp)
		return (perror("malloc"), EXIT_FAILURE);
	sp->diam = ft_atof(arr[2]);
	if (sp->diam <= 0)
		return (free(sp), printerr2(DIAM_ERROR, "sphere\n"), EXIT_FAILURE);
	sp->center = get_point(arr[1]);
	if (!sp->center)
		return (free(sp), printerr("sphere\n"), EXIT_FAILURE);
	sp->color = get_color(arr[3]);
	if (!sp->color)
		return (free_sphere(sp), printerr("sphere\n"), 1);
	if (add_node_object(data, sp, 0))
		return (free_sphere(sp), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	pars_plane(t_minirt *data, char **arr)
{
	t_plane	*pl;

	if (arr_size(arr) != 4 || check_nptr(arr))
		return (printerr(PL_FORMAT), EXIT_FAILURE);
	pl = ft_calloc(1, sizeof(t_plane));
	if (!pl)
		return (perror("malloc"), EXIT_FAILURE);
	pl->point = get_point(arr[1]);
	if (!pl->point)
		return (free(pl), printerr("plane\n"), EXIT_FAILURE);
	pl->axis = get_vector(arr[2]);
	if (!pl->axis)
		return (free_plane(pl), printerr("plane\n"), EXIT_FAILURE);
	pl->color = get_color(arr[3]);
	if (!pl->color)
		return (free_plane(pl), printerr("plane\n"), 1);
	if (add_node_object(data, pl, 1))
		return (free_plane(pl), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	pars_cylinder2(t_minirt *data, char **arr, t_cylinder *cy)
{
	cy->color = get_color(arr[5]);
	if (!cy->color)
		return (free_cylinder(cy), printerr("cylinder\n"), EXIT_FAILURE);
	if (add_node_object(data, cy, 2))
		return (free_cylinder(cy), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	pars_cylindre(t_minirt *data, char **arr)
{
	t_cylinder	*cy;

	if (arr_size(arr) != 6 || check_nptr(arr))
		return (printerr(CY_FORMAT), EXIT_FAILURE);
	cy = ft_calloc(1, sizeof(t_cylinder));
	if (!cy)
		return (perror("malloc"), EXIT_FAILURE);
	cy->diam = ft_atof(arr[3]);
	if (cy->diam < 0.0)
		return (free(cy), printerr2(DIAM_ERROR, "cylinder\n"), 1);
	cy->height = ft_atof(arr[4]);
	if (cy->height < 0.0)
		return (free(cy), printerr(HEIGHT_ERROR), 1);
	cy->center = get_point(arr[1]);
	if (!cy->center)
		return (free_cylinder(cy), printerr("cylinder\n"), EXIT_FAILURE);
	cy->axis = get_vector(arr[2]);
	if (!cy->axis)
		return (free_cylinder(cy), printerr("cylinder\n"), EXIT_FAILURE);
	if (pars_cylinder2(data, arr, cy))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
