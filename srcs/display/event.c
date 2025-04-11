/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:37:48 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/11 19:16:37 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (EXIT_SUCCESS);
}

int	handle_input(t_minirt *data, int keysysm)
{
	//printf("Keycode: %d\n", keysysm);
	if (keysysm == XK_Escape)
		free_minirt(data);
	else if (keysysm == XK_n || keysysm == XK_p)
		move_on_objects(data, keysysm);
	else if (keysysm == XK_Up || keysysm == XK_Down || keysysm == XK_Right
		|| keysysm == XK_Left)
		resize(data, keysysm);
	else if (keysysm == XK_i || keysysm == XK_w || keysysm == XK_j
		|| keysysm == XK_a || keysysm == XK_l || keysysm == XK_d)
		translation(data, keysysm);
	else if (keysysm == XK_1 || keysysm == XK_2 || keysysm == XK_3
		|| keysysm == XK_4 || keysysm == XK_5 || keysysm == XK_6)
		rotation(data, keysysm);
	return (EXIT_SUCCESS);
}
