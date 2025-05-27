/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiech <jpiech@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:52:15 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/27 17:30:31 by jpiech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_welcome_message(void)
{
	printf("\n                       🌟 Welcome to miniRT 🌟\n");
	printf("\n");
	printf(" ****____Object selection____****\n");
	printf(" ➤ Press N to select the next object\n");
	printf(" ➤ Press P to select the previous object\n");
	printf("\n");
	printf(" ****____Object resize____****\n");
	printf(" ➤ Press Up/Down to resize the current object size\n");
	printf(" ➤ Press Right/Left to resize the cylinders height\n");
	printf(" ➤ Planes, camera and light cannot be resized\n");
	printf("\n");
	printf(" ****____Object translation____****\n");
	printf(" ➤ Press Q/A/W/S/E/D to translate the current object");
	printf(" along the Axis X/Y/Z\n\n");
	printf(" ➤ Press A to translate an object to the left (on the X axis)\n");
	printf(" ➤ Press D to translate an object to the right (on the X axis)\n");
	printf(" ➤ Press W to translate an object frontward (on the Z axis)");
	printf(" ➤ Press S to translate an object backward (on the Z axis)\n");
	printf(" ➤ Press E to translate an object upward (on the Y axis)\n");
	printf(" ➤ Press Q to translate an object downward (on the Y axis)\n");
	printf(" ****____Object rotation____****\n");
	printf(" ➤ Press 1/2/3/4/5/6 to rotate the current object");
	printf(" along the Axis X/Y/Z\n\n");
	printf(" ➤ Press 1 to rotate an object upward (on the X axis)\n");
	printf(" ➤ Press 2 to rotate an object downward (on the X axis)\n");
	printf(" ➤ Press 3 to rotate an object to the left (on the Y axis)");
	printf(" ➤ Press 4 to rotate an object to the right (on the Y axis)\n");
	printf(" ➤ Press 5 to rotate an object clockwise (on the Z axis)\n");
	printf(" ➤ Press 6 to rotate an object counterclockwise (on the Z axis)\n");

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
