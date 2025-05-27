/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiech <jpiech@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:37:48 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/27 20:34:23 by jpiech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_keysysm(int keysysm)
{
	if (keysysm == XK_Up || keysysm == XK_Down || keysysm == XK_Right
		|| keysysm == XK_Left)
		ft_putendl_fd("Resizing object...", 1);
	else if (keysysm == XK_q || keysysm == XK_w || keysysm == XK_e
		|| keysysm == XK_a || keysysm == XK_s || keysysm == XK_d)
		ft_putendl_fd("Moving object...", 1);
	else if (keysysm == XK_1 || keysysm == XK_2 || keysysm == XK_3
		|| keysysm == XK_4 || keysysm == XK_5 || keysysm == XK_6)
		ft_putendl_fd("Rotating object...", 1);
}

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
	
	print_keysysm(keysysm);
	data = (t_minirt *)param;
	if (keysysm == XK_n || keysysm == XK_p)
		return (move_on_objects(data, keysysm), EXIT_SUCCESS);
	else if (keysysm == XK_Up || keysysm == XK_Down || keysysm == XK_Right
		|| keysysm == XK_Left)
		resize(data, keysysm);
	else if (keysysm == XK_q || keysysm == XK_w || keysysm == XK_e
		|| keysysm == XK_a || keysysm == XK_s || keysysm == XK_d)
		translation(data, keysysm);
	else if (keysysm == XK_1 || keysysm == XK_2 || keysysm == XK_3
		|| keysysm == XK_4 || keysysm == XK_5 || keysysm == XK_6)
		rotation(data, keysysm);
	else if (keysysm == XK_h)
		print_welcome_message();
	return (EXIT_SUCCESS);
}
