/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:37:48 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/24 13:41:16 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (EXIT_SUCCESS);
}

int	handle_escape(int keysysm, void *param)
{
	t_minirt	*data;

	data = (t_minirt *)param;
	if (keysysm == XK_Escape)
		free_minirt(data);
	return (EXIT_SUCCESS);
}

int	handle_input(int keysysm, void *param)
{
	t_minirt	*data;

	data = (t_minirt *)param;
	if (keysysm == XK_n || keysysm == XK_p)
		move_on_objects(data, keysysm);
	else if (keysysm == XK_Up || keysysm == XK_Down || keysysm == XK_Right
		|| keysysm == XK_Left)
		resize(data, keysysm);
	else if (keysysm == XK_q || keysysm == XK_w || keysysm == XK_e
		|| keysysm == XK_a || keysysm == XK_s || keysysm == XK_d)
		translation(data, keysysm);
	else if (keysysm == XK_1 || keysysm == XK_2 || keysysm == XK_3
		|| keysysm == XK_4 || keysysm == XK_5 || keysysm == XK_6)
		rotation(data, keysysm);
	ray_tracer(data);
	return (EXIT_SUCCESS);
}
