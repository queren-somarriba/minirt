/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:30:16 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/09 18:04:54 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objects	*get_node(t_minirt *data, int index)
{
	t_list	*tmp;

	tmp = *data->objects;
	if (data->current_obj == 0)
		return ((t_objects *)(*data->objects)->content);
	while (((t_objects *)(tmp->content))->index != index - 1)
		tmp = tmp->next;
	return ((t_objects *)(tmp->content));
}

void	update_current_obj(t_minirt *data, int mode)
{
	int	len;

	len = ((t_objects *)ft_lstlast((*data->objects)))->index + 1;
	if (mode == 0)
		data->current_obj = data->current_obj + 1 % len;
	if (mode == 1)
		data->current_obj = (len + data->current_obj - 1) % len;
	//print_obj(data);
}

void	move_on_objects(t_minirt *data, int keysysm)
{
	if (keysysm == XK_n)
		update_current_obj(data, 0);
	if (keysysm == XK_p)
		update_current_obj(data, 1);	
}
