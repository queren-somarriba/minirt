/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:23:40 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/24 19:29:43 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include "minirt.h"

/*EVENT*/
int		handle_no_event(void *data);

int		handle_escape(int keysysm, void *param);

int		handle_input(int keysysm, void *param);

int		close_window(t_minirt *data);

/*RESIZE_AND_TRANSLATE*/
int		resize(t_minirt *data, int keysysm);

int		translation(t_minirt *data, int keysysm);

/*ROTATIONS*/

int		rotation(t_minirt *data, int keysysm);

#endif
