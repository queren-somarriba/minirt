/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:40:05 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/21 13:06:32 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	arr_size(char **arr)
{
	size_t	size;

	size = 0;
	while (*arr++)
		size++;
	return (size);
}

int	str_is_white_space(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isprint(str[i]) && str[i] != ' ')
			return (0);
	}
	return (1);
}

t_color	*get_color(char *str)
{
	char	**c_arr;
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (perror("malloc"), NULL);
	c_arr = ft_split(str, ',');
	if (!c_arr)
		return (free(color), perror("malloc"), color);
	if (arr_size(c_arr) != 3)
		return (free(color), ft_free_arr(c_arr),
			ft_putstr_fd(COLOR_FORMAT, 2), color);
	*color = (t_color){ft_atoi(c_arr[0]), ft_atoi(c_arr[1]), ft_atoi(c_arr[2])};
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
		return (free(color), t_free_arr(c_arr),
			ft_putstr_fd(COLOR_RANGE, 2), NULL);
	return (ft_free_arr(c_arr), color);
}

t_point	*get_point(char *str)
{
	char	**p_arr;
	t_point	*p;

	p = malloc(sizeof(t_point));
	if (!p)
		return (perror("malloc"), NULL);
	p_arr = ft_split(str, ',');
	if (!p_arr)
		return (free(p), perror("malloc"), EXIT_FAILURE);
	if (arr_size(p_arr) != 3)
		return (free(p), ft_free_arr(p_arr),
			ft_putstr_fd(POINT_FORMAT, 2), NULL);
	*p = (t_point){ft_atof(p_arr[0]), ft_atof(p_arr[1]), ft_atof(p_arr[2])};
	return (ft_free_arr(p_arr), p);
}

t_vector	*get_vector(char *str)
{
	char		*v_arr;
	t_vector	*v;

	v = malloc(sizeof(t_vector));
	if (!v)
		return (perror("malloc"), EXIT_FAILURE);
	v_arr = ft_split(str, ',');
	if (!v_arr)
		return (free(v), perror("malloc"), EXIT_FAILURE);
	if (arr_size(v_arr) != 3)
		return (free(v), ft_free_arr(v_arr), ft_putstr_fd(VECT_FORMAT, 2), 1);
	*v = (t_vector){ft_atof(v_arr[0]), ft_atof(v_arr[1]), ft_atof(v_arr[2])};
	return (ft_free_arr(v_arr), v);
}
