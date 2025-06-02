/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:35:30 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/02 12:32:59 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_AND_FREE_H
# define ERROR_AND_FREE_H

# define WINDOW_ERROR "Error\nInvalid window size\n"
# define FILE_ERROR "Error\nminiRT argument must be a unique .rt file\n"
# define OPEN_ERROR " : miniRt cannot open this file\n"
# define OPEN_DIR " : miniRt scene cannot be a directory, must be a file\n"
# define SCENE_ERROR " : Invalid scene\n"
# define AMB_ERROR "Error\nScene must have one unique ambient light\n"
# define CAM_ERROR "Error\nScene must have one unique camera\n"
# define LIGHT_ERROR "Error\nScene must have one unique light\n"
# define MLX_INIT "Error\nmlx_init error\n"
# define MLX_WIN "Error\nmlx_new_window error\n"
# define AMB_FORMAT " : Invalid ambient light format\n"
# define AMB_RATIO " : Invalid ambient light ratio\n"
# define COLOR_FORMAT " : Invalid color format\n"
# define COLOR_RANGE " : Invalid color range\n"
# define CAM_FORMAT " : Invalid camera format\n"
# define POINT_FORMAT " : Invalid point format\n"
# define VECT_FORMAT " : Invalid vector format\n"
# define VECT_RANGE " : Invalid vector range\n"
# define FOV_ERROR " : Invalid field of view angle\n"
# define MIN_FOV_ERROR " : Field of view too small to display anything\n"
# define MAX_FOV_ERROR " : Field of view too wide for display to be coherent\n"
# define LIGHT_FORMAT " : Invalid light format\n"
# define BRIGHT_RATIO " : Invalid light brightness ratio\n"
# define SP_FORMAT " : Invalid sphere format\n"
# define DIAM_ERROR " : Invalid diameter\n"
# define PL_FORMAT " : Invalid plane format\n"
# define CY_FORMAT " : Invalid cylinder format\n"
# define HEIGHT_ERROR " : Invalid height\n" 

/*FREE_OBJECTS*/
void	free_sphere(t_sphere *sp);

void	free_plane(t_plane *pl);

void	free_cylinder(t_cylinder *cy);

void	free_objects_lst(t_list **lst);

/*FREE_SCENE*/
void	free_amb(t_amb_light *amb);

void	free_cam(t_cam *cam);

void	free_light(t_light *light);

int		free_minirt(t_minirt *data);

#endif
