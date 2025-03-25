/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:37:48 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/25 17:23:21 by qsomarri         ###   ########.fr       */
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
	if (keysysm == XK_Escape)
		free_minirt(data);
	return (EXIT_SUCCESS);
}
