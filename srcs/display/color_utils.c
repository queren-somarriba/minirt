/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:40:34 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/25 19:13:33 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	clamp_color(t_color c)
{
	return ((t_color){ft_min(c.r, 255), ft_min(c.g, 255), ft_min(c.b, 255)});
}

int	encode_rgb(t_color c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}

t_color	add_color(t_color c1, t_color c2, float c2_ratio)
{
	return (clamp_color((t_color){(1.0f - c2_ratio) * c1.r + c2.r * c2_ratio,
			(1.0f - c2_ratio) * c1.g + c2.g * c2_ratio,
			(1.0f - c2_ratio) * c1.b + c2.b * c2_ratio}));
}
