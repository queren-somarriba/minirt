/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiech <jpiech@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:13:14 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/26 18:10:40 by jpiech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	diffuse_reflexion(t_inter *i, t_light *l, t_color c, t_vector to_light)
{
	t_color		diffuse;
	float		x;

	to_light = normalize_vect(to_light);
	x = dot_product(i->normal, to_light);
	if (x < 0.0f)
		x = 0.0f;
	x *= l->brightness;
	diffuse = clamp_color((t_color){i->c.r * x, i->c.g * x, i->c.b * x});
	diffuse = clamp_color((t_color){c.r + diffuse.r,
			c.g + diffuse.g, c.b + diffuse.b});
	return (diffuse);
}

int	is_in_shadow(t_minirt *data, t_inter *inter, t_vector to_light)
{
	t_ray		shadow_ray;
	t_inter		*tmp;
	float		light_dist;

	light_dist = vect_length(to_light);
	shadow_ray.p = (t_vector){inter->p.x,
		inter->p.y, inter->p.z};
	shadow_ray.v = normalize_vect(to_light);
	tmp = closest_inter_shadow(data, shadow_ray, inter->obj_index);
	if (tmp && tmp->dist > 1e-6 && tmp->dist < light_dist)
		return (free(tmp), 1);
	if (tmp)
		free(tmp);
	return (0);
}

t_color	final_color(t_minirt *data, t_inter *inter)
{
	t_color		final;
	t_vector	to_light;

	to_light = (t_vector){data->light->p->x - inter->p.x,
		data->light->p->y - inter->p.y, data->light->p->z - inter->p.z};
	final = add_color(inter->c, *(data->amb->color), data->amb->ratio);
	if (!is_in_shadow(data, inter, to_light))
	 	final = diffuse_reflexion(inter, data->light, final, to_light);
	return (clamp_color(final));
}
