/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:54:06 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/24 15:04:10 by qsomarri         ###   ########.fr       */
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
# include <../mlx_linux/mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../libft/includes/libft.h"
# include "structs.h"
# include "error.h"
# include "parser.h"
# include "display.h"
# include "vector.h"
# include "intersections.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# ifndef M_PI
#  define M_PI (float)3.14159265358979323846
# endif

/*LIST_UTILS*/
void		move_on_objects(t_minirt *data, int keysysm);

t_objects	*get_node(t_minirt *data, int index);

/*UTILS*/
void		ray_tracer(t_minirt *data);

/*OUTPUTS*/
int			print_object(t_objects *node);

/*TRANSFORMATIONS*/
int			resize(t_minirt *data, int keysysm);

int			translation(t_minirt *data, int keysysm);

int			rotation(t_minirt *data, int keysysm);


#endif
