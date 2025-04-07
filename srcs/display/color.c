/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:13:14 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/07 16:14:13 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	encode_rgb(t_color c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}

t_color	add_color(t_color c1, t_color c2, float c2_ratio)
{
	return ((t_color){(1 - c2_ratio) * c1.r + c2.r * c2_ratio,
		(1 - c2_ratio) * c1.g + c2.g * c2_ratio,
		(1 - c2_ratio) * c1.b + c2.b * c2_ratio});
}

t_color	diffuse_reflexion(t_inter *inter, t_light *light, t_color color)
{
	t_color		diffuse;
	t_vector	light_vect;
	float		x;
	float		dist;

	light_vect = (t_vector){light->p->x - inter->p.x,
		light->p->y - inter->p.y, light->p->z - inter->p.z};
	dist = vect_length(light_vect);
	light_vect = normalize_vect(light_vect);
	x = dot_product(light_vect, inter->normal);
	if (x < 0)
		x = 0;
	x /= powf(dist, 2);
	diffuse = (t_color){ft_min(inter->c.r * x, 255),
		ft_min(inter->c.g * x, 255), ft_min(inter->c.b * x, 255)};
	diffuse = (t_color){ft_min(color.r + diffuse.r, 255),
		ft_min(color.g + diffuse.g, 255), ft_min(color.b + diffuse.b, 255)};
	return (add_color(color, diffuse, light->brightness));
}

int	is_in_shadow(t_minirt *data, t_inter *inter, t_light *light)
{
	t_ray		shadow_ray;
	t_inter		*tmp;
	t_vector	to_light;
	float		dist;

	to_light = (t_vector){light->p->x - inter->p.x,
		light->p->y - inter->p.y, light->p->z - inter->p.z};
	dist = vect_length(to_light);
	to_light = normalize_vect(to_light);
	shadow_ray.p = (t_point){
		inter->p.x + 0.001 * to_light.x,
		inter->p.y + 0.001 * to_light.y, inter->p.z + 0.001 * to_light.z};
	shadow_ray.v = to_light;
	tmp = closest_inter(data, shadow_ray);
	if (tmp && tmp->dist < dist)
		return (free(tmp), 1);
	return (free(tmp), 0);
}

// bool	is_in_shadow(t_minirt *data, t_inter *inter, t_light *light)
// {
// 	t_ray	shadow_ray;
// 	t_inter	*tmp;
// 	float		dist;

// 	shadow_ray.v = (t_vector){light->p->x - inter->p.x,
// 		light->p->y - inter->p.y, light->p->z - inter->p.z};
// 	dist = vect_length(shadow_ray.v);
// 	shadow_ray.v = normalize_vect(shadow_ray.v);
// 	shadow_ray.p = inter->p;
// 	tmp = closest_inter(data, shadow_ray);
// 	if (tmp && tmp->dist < dist)
// 		return (free(tmp), true);
// 	return (free(tmp), false);
// }

t_color	final_color(t_minirt *data, t_inter *inter)
{
	t_color	final;

	final = add_color(inter->c, *(data->amb->color), data->amb->ratio);
	if (!is_in_shadow(data, inter, data->light))
		final = diffuse_reflexion(inter, data->light, final);
	else
		final = add_color(final, (t_color){0, 0, 0}, 0);
	return (final);
}

// t_color	let_there_be_light(t_minirt *data, t_inter *inter)
// {
// 	t_ray	light_ray;
// 	t_color	final;
// 	float	dist;

// 	light_ray.p = inter->p;
// 	light_ray.v = normalize_vect((t_vector){data->light->p->x - inter->p.x,
// 		data->light->p->y - inter->p.y, data->light->p->z - inter->p.z});
// 	final = add_color(inter->c, *(data->amb->color), data->amb->ratio);
// 	final = diffuse_reflexion(inter, data->light, final);
// 	dist = vect_length((t_vector){light_ray.p.x - data->light->p->x,
// 		light_ray.p.y - data->light->p->y, light_ray.p.z - data->light->p->z});
// 	if (!inter_obj(data, &light_ray, dist))
// 		final = diffuse_reflexion(inter, data->light, final);
// 	return (final);
// }

// bool	inter_obj(t_minirt *rt, t_ray *ray, float max)
// {
// 	t_list		*node;
// 	t_inter		*close;
// 	t_inter		*inter;
// 	bool		is_in_shadow;

// 	node = *(rt->obj);
// 	close = calloc_utils();
// 	is_in_shadow = false;
// 	while (objects)
// 	{
// 		if (objects->i != ray->inter->i)
// 		{
// 			inter = NULL;
// 			inter_space(ray, objects, &inter);
// 			if (inter && inter->dist > E && inter->dist < max)
// 				saving_space(&max, &close, inter, &is_in_shadow);
// 			else
// 				free_inter(inter);
// 		}
// 		objects = objects->next;
// 	}
// 	if (close)
// 		ray->inter = close;
// 	return (is_in_shadow);
// }

// void	inter_space(t_ray *ray, t_objects *objects, t_inter **intersection)
// {
// 	if (objects->type == PLANE)
// 		*intersection = intersect_plane(ray, &objects->fig.pl);
// 	else if (objects->type == SPHERE)
// 		*intersection = intersect_sphere(ray, &objects->fig.sp);
// 	else if (objects->type == CYLINDER)
// 		*intersection = intersect_cylinder(ray, &objects->fig.cy);
// }

// void	saving_space(float *max_distance, t_inter **closest_intersection,
// 	t_inter *intersection, bool *is_in_shadow)
// {
// 	*max_distance = intersection->dist;
// 	free_inter(*closest_intersection);
// 	*closest_intersection = intersection;
// 	*is_in_shadow = true;
// }
