/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minirt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:01:24 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/17 18:07:40 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static const char	*handle_decimal(const char *nptr, double *res)
{
	double	factor;

	factor = 0.1;
	nptr++;
	while (*nptr && ft_isdigit(*nptr))
	{
		*res += (*nptr++ - '0') * factor;
		factor *= 0.1;
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

double	ft_atof(const char *nptr)
{
	double	res;
	int		e;
	int		sign;

	res = 0.0;
	e = 0;
	sign = 1;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
		res = res * 10.0 - '0' + *nptr++;
	if (*nptr == '.')
		nptr = handle_decimal(nptr, &res);
	if (*nptr == 'e' || *nptr == 'E')
		e = handle_e(nptr);
	res *= pow(10, e);
	return (res * sign);
}
