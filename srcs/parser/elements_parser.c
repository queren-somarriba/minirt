/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:40:11 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/09 18:13:52 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	*get_color(char *str)
{
	char	**c_arr;
	t_color	*color;

	color = ft_calloc(1, sizeof(t_color));
	if (!color)
		return (perror("malloc"), NULL);
	c_arr = ft_split(str, ',');
	if (!c_arr)
		return (free(color), perror("malloc"), NULL);
	if (arr_size(c_arr) != 3 || ft_str_equal(c_arr[2], "\n"))
		return (ft_free_array(c_arr),
			printerr(COLOR_FORMAT), NULL);
	*color = (t_color){ft_atoi(c_arr[0]), ft_atoi(c_arr[1]), ft_atoi(c_arr[2])};
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
		return (free(color), ft_free_array(c_arr), printerr(COLOR_RANGE), NULL);
	return (ft_free_array(c_arr), color);
}

t_point	*get_point(char *str)
{
	char	**p_arr;
	t_point	*p;

	p = ft_calloc(1, sizeof(t_point));
	if (!p)
		return (perror("malloc"), NULL);
	p_arr = ft_split(str, ',');
	if (!p_arr)
		return (free(p), perror("malloc"), NULL);
	if (arr_size(p_arr) != 3)
		return (free(p), ft_free_array(p_arr), printerr(POINT_FORMAT), NULL);
	*p = (t_point){ft_atof(p_arr[0]), ft_atof(p_arr[1]), ft_atof(p_arr[2])};
	return (ft_free_array(p_arr), p);
}

t_vector	*get_vector(char *str)
{
	char		**v_arr;
	t_vector	*v;

	v = ft_calloc(1, sizeof(t_vector));
	if (!v)
		return (perror("malloc"), NULL);
	v_arr = ft_split(str, ',');
	if (!v_arr)
		return (free(v), perror("malloc"), NULL);
	if (arr_size(v_arr) != 3)
		return (free(v), ft_free_array(v_arr), printerr(VECT_FORMAT), NULL);
	*v = (t_vector){ft_atof(v_arr[0]), ft_atof(v_arr[1]), ft_atof(v_arr[2])};
	if (v->x < -1.0 || v->x > 1.0 || v->y < -1.0 || v->y > 1.0
		|| v->z < -1.0 || v->z > 1.0)
		return (free(v), ft_free_array(v_arr), printerr(VECT_RANGE), NULL);
	*v = normalize_vect(*v);
	return (ft_free_array(v_arr), v);
}
