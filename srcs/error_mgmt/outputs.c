/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:52:15 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/23 18:21:42 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	printerr(char *str)
{
	if (str)
		ft_putstr_fd(str, 2);
}

void	printerr2(char *str1, char *str2)
{
	printerr(str1);
	printerr(str2);
}

int	print_object(t_objects *node)
{
	int		index;

	index = node->index;
	if (node->type == AMB)
		printf("[%d] - ambient light\n", index);
	if (node->type == CAM)
		printf("[%d] - camera\n", index);
	if (node->type == LIGHT)
		printf("[%d] - light\n", index);
	if (node->type == SPHERE)
		printf("[%d] - sphere\n", index);
	if (node->type == PLANE)
		printf("[%d] - plane-->\n", index);
	if (node->type == CYLINDER)
		printf("[%d] - cylinder-->\n", index);
	return (EXIT_SUCCESS);
}
