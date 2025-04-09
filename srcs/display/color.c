/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:13:14 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/09 19:35:34 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	diffuse_reflexion(t_inter *inter, t_light *light, t_color color, t_vector to_light)
{
	t_color		diffuse;
	float		x;

	to_light = normalize_vect(to_light);
	x = dot_product(inter->normal, to_light);
	if (x < 0)
		x = 0;
	x *= light->brightness;
	diffuse = clamp_color((t_color){inter->c.r * x,
		inter->c.g * x, inter->c.b * x});
	diffuse = clamp_color((t_color){color.r + diffuse.r,
		color.g + diffuse.g, color.b + diffuse.b});
	return (diffuse);
}

int	is_in_shadow(t_minirt *data, t_inter *inter, t_vector to_light)
{
	t_ray		shadow_ray;
	t_inter		*tmp;
	float		light_dist;

	light_dist = vect_length(to_light);
	shadow_ray.p = (t_point){inter->p.x + inter->normal.x,
		inter->p.y + inter->normal.y, inter->p.z + inter->normal.z};
	shadow_ray.v = normalize_vect(to_light);
	tmp = closest_inter_shadow(data, shadow_ray, inter->obj_index);
	if (tmp && tmp->dist > 1e-6 && tmp->dist < light_dist)
		return(free(tmp), 1);
	else if (tmp)
		free(tmp);
	if (tmp)
	    free(tmp);
	return (0);
}

t_color	final_color(t_minirt *data, t_inter *inter)
{
	t_color	final;
	t_vector to_light;

	to_light = (t_vector){data->light->p->x - inter->p.x,
		data->light->p->y - inter->p.y, data->light->p->z - inter->p.z};
	final = add_color(inter->c, *(data->amb->color), data->amb->ratio);
	if (!is_in_shadow(data, inter, to_light))
		final = diffuse_reflexion(inter, data->light, final, to_light);
	return (clamp_color(final));
}



/*
no inter = no shadow
object != obj_inter
{
	if (inter && inter->dist > E && inter->dist < light_dist)
		-->SHADOW
}

bool	inter_obj(t_rt *rt, t_ray *ray, double max)
{
	t_objects	*objects;
	t_inter		*close;
	t_inter		*inter;
	bool		is_in_shadow;

	objects = rt->sc->obj;
	close = calloc_utils();
	is_in_shadow = false;
	while (objects)
	{
		if (objects->i != ray->inter->i)
		{
			inter = NULL;
			inter_space(ray, objects, &inter);
			if (inter && inter->dist > E && inter->dist < max)
				saving_space(&max, &close, inter, &is_in_shadow);
			else
				free_inter(inter);
		}
		objects = objects->next;
	}
	if (close)
		ray->inter = close;
	return (is_in_shadow);
}*/