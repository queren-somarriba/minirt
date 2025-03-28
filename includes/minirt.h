/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:54:06 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/28 18:08:25 by qsomarri         ###   ########.fr       */
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

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

/*UTILS*/
void	ray_tracer(t_minirt *data);
/*OUTPUTS*/
int			print_scene(t_minirt *data);

int			print_objects(t_list **lst);

#endif
