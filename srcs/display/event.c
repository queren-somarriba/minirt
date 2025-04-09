/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:37:48 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/09 17:39:56 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (EXIT_SUCCESS);
}

int	handle_input(int keysysm, t_minirt *data)
{
	//printf("Keycode: %d\n", keysysm);
	if (keysysm == XK_Escape)
		free_minirt(data);
	if (keysysm == XK_n || keysysm == XK_p)
		move_on_objects(data, keysysm);
	if (keysysm == 65363 || keysysm == 65361 || keysysm == 65362
		|| keysysm == 65364)
		printf("diameter/height\n");//change diam/height
	if (keysysm == XK_i || keysysm == XK_w || keysysm == XK_j
		|| keysysm == XK_a || keysysm == XK_l || keysysm == XK_d)
		printf("translate obj\n");//transaltion
	if (keysysm == XK_1 || keysysm == XK_2 || keysysm == XK_3)
		printf("rotate obj\n");//rotation
	return (EXIT_SUCCESS);
}
