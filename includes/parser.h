/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:36:09 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/09 16:15:23 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*ELEMENTS_PARSER*/

t_color		*get_color(char *str);

t_point		*get_point(char *str);

t_vector	*get_vector(char *str);

/*FILE_PARSER*/
int			pars_file(t_minirt *data, char *str);

/*FT_ATOF*/
float		ft_atof(const char *nptr);

/*OBJECTS_PARSER*/
int			pars_sphere(t_minirt *data, char **arr);

int			pars_plane(t_minirt *data, char **arr);

int			pars_cylindre(t_minirt *data, char **arr);

int			add_node_object(t_minirt *data, void *obj, t_obj_id id);

/*SCENE_PARSER*/
int			pars_ambient_light(t_minirt *data, char **arr);

int			pars_camera(t_minirt *data, char **arr);

int			pars_light(t_minirt *data, char **arr);

/*UTILS_PARSER*/

int			str_is_white_space(char *str);

int			check_nptr(char **arr);

size_t		arr_size(char **arr);

#endif
