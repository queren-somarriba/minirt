/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiech <jpiech@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:54:06 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/27 17:31:31 by jpiech           ###   ########.fr       */
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
# include "error_and_free.h"
# include "parser.h"
# include "display.h"
# include "ui.h"
# include "intersections.h"

# define WIN_WIDTH 80
# define WIN_HEIGHT 60

# ifndef M_PI
#  define M_PI (float)3.14159265358979323846
# endif

/*LIST_UTILS*/
void		move_on_objects(t_minirt *data, int keysysm);

t_objects	*get_node(t_minirt *data, int index);

/*OUTPUTS*/
int			print_object(t_objects *node);

void		printerr(char *str);

void		printerr2(char *str1, char *str2);

void		print_welcome_message(void);

void		printerr_line(int count, char *str);

/*VECTOR_UTILS*/
float		vect_length(t_vector v);

t_vector	add_vector(t_vector v1, t_vector v2);

t_vector	sub_vector(t_vector v1, t_vector v2);

t_vector	vector_scale(t_vector v, float x);

float		dot_product(t_vector v1, t_vector v2);

/*VECTOR_UTILS 2*/
t_vector	normalize_vect(t_vector v);

t_vector	mult_vect(t_vector v1, t_vector v2);

#endif
