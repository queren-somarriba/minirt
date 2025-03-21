/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:39:17 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/21 17:32:47 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_amb(t_amb_light *amb)
{
	if (amb)
	{
		if (amb->color)
		{
			free(amb->color);
			amb->color = NULL;
		}
		free(amb);
		amb = NULL;
	}
}

void	free_cam(t_cam *cam)
{
	if (cam)
	{
		if (cam->p)
		{
			free(cam->p);
			cam->p = NULL;
		}
		if (cam->v)
		{
			free(cam->v);
			cam->v = NULL;
		}
		free(cam);
		cam = NULL;
	}
}

void	free_light(t_light *light)
{
	if (light)
	{
		if (light->p)
		{
			free(light->p);
			light->p = NULL;
		}
		free(light);
		light = NULL;
	}
}

void	free_scene(t_scene *scene)
{
	if (scene)
	{
		if (scene->amb)
			free_amb(scene->amb);
		if (scene->cam)
			free_cam(scene->cam);
		if (scene->light)
			free_light(scene->light);
		free(scene);
		scene = NULL;
	}	
}

void	free_minirt(t_minirt *data)
{
	if (data)
	{
		if (data->scene)
			free_scene(data->scene);
		if (data->objects)
			free_objects_lst(data->objects);
	}
}
