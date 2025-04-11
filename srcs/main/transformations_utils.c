/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:55:51 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/11 19:19:43 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rotate_x(t_vector *v, float angle)
{
	v->y = v->y * cosf(angle) - v->z * sinf(angle);
	v->z = v->y * sinf(angle) + v->z * cosf(angle);
}

void	rotate_y(t_vector *v, float angle)
{
	v->x = v->x * cosf(angle) + v->z * sinf(angle);
	v->z = -v->x * sinf(angle) + v->z * cosf(angle);
}

void	rotate_z(t_vector *v, float angle)
{
	v->x = v->x * cosf(angle) - v->y * sinf(angle);
	v->y = v->x * sinf(angle) + v->y * cosf(angle);
}
