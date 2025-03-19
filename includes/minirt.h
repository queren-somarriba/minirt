/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:54:06 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/19 19:29:49 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "structs.h"

# define FILE_ERROR "Error\nminiRT argument must be a .rt file\n"
# define OPEN_ERROR "Error\n : miniRt cannot open this file\n"
# define SCENE_ERROR "Error\nInvalid scene !\n"
# define AMB_ERROR "Error\nScene must have one unique ambient light\n"
# define CAM_ERROR "Error\nScene must have one unique camera\n"
# define LIGHT_ERROR "Error\nScene must have one unique light\n"
# define AMB_FORMAT "Error\nInvalid ambient light format\n"
# define AMB_RATIO "Error\nInvalid ambient light ratio\n"
# define COLOR_FORMAT "Error\nInvalid color format : "
# define COLOR_RANGE "Error\nInvalid color range : "
# define CAM_FORMAT "Error\nInvalid camera format\n"
# define POINT_FORMAT "Error\nInvalid point format : "
# define VECT_FORMAT "Error\nInvalid vector format : "
# define FOV_ERROR "Error\nInvalid field of view angle\n"
# define LIGHT_FORMAT "Error\nInvalid light format\n"
# define BRIGHT_RATIO "Error\ninvalid light brightness ratio\n"

/*PARSER*/
int			check_file(char *str);

int			pars_file(t_minirt *data, char *str);

int			str_is_white_space(char *str);

t_color		*get_color(char *str);

size_t		arr_size(char **arr);

int			pars_line(t_minirt *data, char *str);

int			pars_ambient_light(t_minirt *data, char **arr);

t_point		*get_point(char *str);

/*UTILS*/
double		ft_atof(const char *nptr);

/*OUTPUTS*/
int			print_scene(t_minirt *data);

#endif
