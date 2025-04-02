/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:05:57 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/02 17:20:10 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include "minirt.h"
/*INTERSECTIONS*/
t_inter	*closest_inter(t_minirt *data, t_ray ray);

/*CYLINDER*/
t_inter	*inter_cylinder(t_cylinder *cy, t_ray ray);

/*PLANE*/
t_inter	*inter_plane(t_plane *pl, t_ray ray);

/*SPHERE*/
t_inter	*inter_sphere(t_sphere *sp, t_ray ray);

float	quad(float a, float b, float c);

#endif
