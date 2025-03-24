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

int	pars_ambient_light(t_minirt *data, char **arr)
{
	t_amb_light	*amb;

	if (arr_size(arr) != 3)
		return (printerr(AMB_FORMAT), EXIT_FAILURE);
	amb = ft_calloc(1, sizeof(t_amb_light));
	if (!amb)
		return (perror("malloc"), EXIT_FAILURE);
	amb->ratio = ft_atof(arr[1]);
	if (amb->ratio < 0.0 || amb->ratio > 1.0)
		return (free(amb), printerr(AMB_RATIO), EXIT_FAILURE);
	amb->color = get_color(arr[2]);
	if (!amb->color)
		return (free(amb), printerr("ambient light\n"), EXIT_FAILURE);
	data->scene->amb = amb;
	return (EXIT_SUCCESS);
}

int	pars_camera(t_minirt *data, char **arr)
{
	t_cam	*cam;

	if (arr_size(arr) != 4)
		return (printerr(CAM_FORMAT), EXIT_FAILURE);
	cam = ft_calloc(1, sizeof(t_cam));
	if (!cam)
		return (perror("malloc"), EXIT_FAILURE);
	cam->p = get_point(arr[1]);
	if (!cam->p)
		return (free(cam), printerr("camera\n"), EXIT_FAILURE);
	cam->v = get_vector(arr[2]);
	if (!cam->v)
		return (free(cam->p), free(cam), printerr("camera\n"), 1);
	cam->fov = ft_atoi(arr[3]);
	if (cam->fov < 0 || cam->fov > 180)
		return (free(cam->p), free(cam->v), free(cam), printerr(FOV_ERROR), 1);
	data->scene->cam = cam;
	return (EXIT_SUCCESS);
}

int	pars_light(t_minirt *data, char **arr)
{
	t_light	*light;

	if (arr_size(arr) != 4)
		return (printerr(LIGHT_FORMAT), EXIT_FAILURE);
	light = ft_calloc(1, sizeof(t_light));
	if (!light)
		return (perror("malloc"), EXIT_FAILURE);
	light->p = get_point(arr[1]);
	if (!light->p)
		return (free(light), printerr("light\n"), EXIT_FAILURE);
	light->brightness = ft_atof(arr[2]);
	if (light->brightness < 0.0 || light->brightness > 1.0)
		return (free(light->p), free(light), printerr(BRIGHT_RATIO), 1);
	data->scene->light = light;
	return (EXIT_SUCCESS);
}
