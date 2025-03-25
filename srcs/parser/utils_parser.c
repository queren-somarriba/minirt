/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:40:05 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/25 14:13:57 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	arr_size(char **arr)
{
	size_t	size;

	size = 0;
	while (*arr++)
		size++;
	return (size);
}

int	str_is_white_space(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isprint(str[i]))
			return (0);
	}
	return (1);
}

int	check_nptr(char **arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
		{
			if ((arr[i][j] < '0' || arr[i][j] > '9')
				&& (arr[i][j] != '+' && arr[i][j] != '-'
				&& arr[i][j] != '.' && arr[i][j] != ','
				&& arr[i][j] != '\n'))
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
