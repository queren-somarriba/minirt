/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:12:15 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/26 19:22:11 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "minirt.h"

/*EVENT*/
int	handle_no_event(void *data);

int	handle_input(int keysysm, t_minirt *data);

int	close_window(t_minirt *data);

int	render(t_minirt *data);

#endif
