/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:01:24 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/25 19:20:02 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static const char	*handle_decimal(const char *nptr, float *res)
{
	float	factor;

	factor = 0.1f;
	nptr++;
	while (*nptr && ft_isdigit(*nptr))
	{
		*res += (*nptr++ - '0') * factor;
		factor *= 0.1f;
	}
	return (nptr);
}

static int	handle_e(const char *nptr)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (ft_isdigit(*nptr))
		i = i * 10 + (*nptr++ - '0');
	return (i * sign);
}

float	ft_atof(const char *nptr)
{
	float	res;
	int		e;
	int		sign;

	res = 0.0f;
	e = 0;
	sign = 1;
	if (ft_str_equal(nptr, "INFINITY"))
		return (INFINITY);
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
		res = res * 10.0f - '0' + *nptr++;
	if (*nptr == '.')
		nptr = handle_decimal(nptr, &res);
	if (*nptr == 'e' || *nptr == 'E')
		e = handle_e(nptr);
	res *= powf(10.0f, e);
	return (res * sign);
}
