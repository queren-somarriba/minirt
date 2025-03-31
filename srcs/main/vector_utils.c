/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:31:11 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/31 14:51:38 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	vect_norm(t_vector v)
{
	return (sqrt(pow(v.x, 2.0) + pow(v.y, 2.0) + pow(v.z, 2.0)));
}

t_vector	add_vector(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

t_vector	substract_vector(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

t_vector	scalar_mult(t_vector v, float x)
{
	return ((t_vector){x * v.x, x * v.y, x * v.z});
}

float	dot_product(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
