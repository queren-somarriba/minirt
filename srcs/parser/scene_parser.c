/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:52:44 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/19 19:33:23 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	pars_ambient_light(t_minirt *data, char **arr, int count)
{
	t_amb_light	*amb;

	if (arr_size(arr) != 3 || check_nptr(arr))
		return (printerr_line(count, AMB_FORMAT), EXIT_FAILURE);
	amb = ft_calloc(1, sizeof(t_amb_light));
	if (!amb)
		return (perror("malloc"), EXIT_FAILURE);
	amb->ratio = ft_atof(arr[1]);
	if (amb->ratio < 0.0f || amb->ratio > 1.0f)
		return (free(amb), printerr_line(count, AMB_RATIO), EXIT_FAILURE);
	amb->color = get_color(arr[2], count);
	if (!amb->color)
		return (free(amb), EXIT_FAILURE);
	data->amb = amb;
	if (add_node_object(data, amb, AMB))
		return (free_amb(amb), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	pars_camera(t_minirt *data, char **arr, int count)
{
	t_cam	*cam;

	if (arr_size(arr) != 4 || check_nptr(arr))
		return (printerr_line(count, CAM_FORMAT), EXIT_FAILURE);
	cam = ft_calloc(1, sizeof(t_cam));
	if (!cam)
		return (perror("malloc"), EXIT_FAILURE);
	cam->p = get_point(arr[1], count);
	if (!cam->p)
		return (free(cam), EXIT_FAILURE);
	cam->v = get_vector(arr[2], count);
	if (!cam->v)
		return (free(cam->p), free(cam), 1);
	cam->fov = ft_atoi(arr[3]);
	if (cam->fov < 0 || cam->fov > 180)
		return (free(cam->p), free(cam->v), free(cam), printerr(FOV_ERROR), 1);
	data->cam = cam;
	if (add_node_object(data, cam, CAM))
		return (free_cam(cam), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	pars_light(t_minirt *data, char **arr, int count)
{
	t_light	*light;

	if (arr_size(arr) != 3 || check_nptr(arr))
		return (printerr_line(count, LIGHT_FORMAT), EXIT_FAILURE);
	light = ft_calloc(1, sizeof(t_light));
	if (!light)
		return (perror("malloc"), EXIT_FAILURE);
	light->p = get_point(arr[1], count);
	if (!light->p)
		return (free(light), EXIT_FAILURE);
	light->brightness = ft_atof(arr[2]);
	if (light->brightness < 0.0f || light->brightness > 1.0f)
		return (free(light->p), free(light),
			printerr_line(count, BRIGHT_RATIO), EXIT_FAILURE);
	data->light = light;
	if (add_node_object(data, light, LIGHT))
		return (free_light(light), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
