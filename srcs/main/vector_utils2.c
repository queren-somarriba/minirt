/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:19:32 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/31 14:51:43 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	normalize_vect(t_vector v)
{
	float	a;

	a = vect_norm(v);
	return ((t_vector){v.x / a, v.y / a, v.z / a});
}
