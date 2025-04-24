/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:12:15 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/24 12:57:18 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "minirt.h"
/*COLOR*/
t_color	final_color(t_minirt *data, t_inter *inter);

/*COLOR_UTILS*/
t_color	clamp_color(t_color c);

int		encode_rgb(t_color c);

t_color	add_color(t_color c1, t_color c2, float c2_ratio);

/*EVENT*/
int		handle_no_event(void *data);

int		handle_escape(int keysysm, void *param);

int		handle_input(int keysysm, void *param);

int		close_window(t_minirt *data);

/*DISPLAY*/
void	img_pix_put(t_img img, int x, int y, int color);

int		render(t_minirt *data);

#endif
