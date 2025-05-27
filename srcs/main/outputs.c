/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiech <jpiech@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:52:15 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/27 17:48:43 by jpiech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_welcome_message(void)
{
	printf("\n                       🌟 Welcome to miniRT 🌟\n\n");
	printf(" ➤ Press N to select the next object\n");
	printf(" ➤ Press P to select the previous object\n\n");
	printf(" ➤ Press Up/Down to resize the current object size\n");
	printf(" ➤ Press Right/Left to resize cylinders height\n");
	printf(" ➤ Planes, camera and light cannot be resized\n\n");
	printf(" ➤ Press A/D to translate an object on the X axis\n");
	printf(" ➤ Press W/S to translate an object on the Z axis\n");
	printf(" ➤ Press E/Q to translate an object on the Y axis\n\n");
	printf(" ➤ Press 1/2 to rotate an object on the X axis\n");
	printf(" ➤ Press 3/4 to rotate an object on the Y axis\n");
	printf(" ➤ Press 5/6 to rotate an object on the Z axis\n");
	printf(" ➤ Spheres cannot be rotated\n\n");
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

void	printerr_line(int count, char *str)
{
	char	*line;

	line = ft_itoa(count);
	printerr("Error\n");
	printerr2("line ", line);
	printerr(str);
	free(line);
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
