/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:35:30 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/24 19:30:01 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_AND_FREE_H
# define ERROR_AND_FREE_H

# define WINDOW_ERROR "Error\nInvalid window size\n"
# define FILE_ERROR "Error\nminiRT argument must be a .rt file\n"
# define OPEN_ERROR " : miniRt cannot open this file\n"
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
# define VECT_RANGE "Error\nInvalid vector range : "
# define FOV_ERROR "Error\nInvalid field of view angle\n"
# define LIGHT_FORMAT "Error\nInvalid light format\n"
# define BRIGHT_RATIO "Error\nInvalid light brightness ratio\n"
# define SP_FORMAT "Error\nInvalid sphere format\n"
# define DIAM_ERROR "Error\nInvalid diameter : "
# define PL_FORMAT "Error\nInvalid plane format\n"
# define CY_FORMAT "Error\nInvalid cylinder format\n"
# define HEIGHT_ERROR "Error\n Invalid height : cylinder\n" 
# define MLX_INIT "Error\nmlx_init error\n"
# define MLX_WIN "Error\nmlx_new_window error\n"

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
