/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:52:15 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/24 13:45:56 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_welcome_message(void)
{
	printf("\n                       🌟 Welcome to MiniRT 🌟\n");
	printf("\n");
	printf(" ➤ Press N to move to the next object\n");
	printf(" ➤ Press P to move to the previous object\n");
	printf("\n");
	printf(" ➤ Press Up/Down to resize the current object size\n");
	printf(" ➤ Press Right/Left to resize the cylinders height\n");
	printf("\n");
	printf(" ➤ Press Q/A/W/S/E/D to translate the current object");
	printf(" along the Axis X/Y/Z\n\n");
	printf(" ➤ Press 1/2/3/4/5/6 to rotate the current object");
	printf(" along the Axis X/Y/Z\n\n");
	printf(" ➤ Press ESC to quit\n\n");
}

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
		printf("[%d] - plane\n", index);
	if (node->type == CYLINDER)
		printf("[%d] - cylinder\n", index);
	return (EXIT_SUCCESS);
}
