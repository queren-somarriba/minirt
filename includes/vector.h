/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:22:35 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/04 16:56:10 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "minirt.h"

/*VECTOR_UTILS*/
float		vect_lenght(t_vector v);

t_vector	add_vector(t_vector v1, t_vector v2);

t_vector	substract_vector(t_vector v1, t_vector v2);

t_vector	scalar_mult(t_vector v, float x);

float		dot_product(t_vector v1, t_vector v2);

/*VECTOR_UTILS 2*/
t_vector	normalize_vect(t_vector v);

t_vector	mult_vect(t_vector v1, t_vector v2);

#endif
