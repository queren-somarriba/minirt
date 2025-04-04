/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:19:32 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/04 16:58:32 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	normalize_vect(t_vector v)
{
	float	a;

	a = vect_lenght(v);
	return ((t_vector){v.x / a, v.y / a, v.z / a});
}

t_vector	mult_vect(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.y * v2.z - v2.y * v1.z,
		v1.z * v2.x - v2.z * v1.x, v1.x * v2.y * v2.x * v1.y});
}
