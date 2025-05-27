/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiech <jpiech@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:30:16 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/27 15:20:53 by jpiech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objects	*get_node(t_minirt *data, int index)
{
	t_list	*tmp;

	tmp = *data->objects;
	if (data->current_obj == 0)
		return ((t_objects *)(*data->objects)->content);
	while (((t_objects *)(tmp->content))->index != index)
		tmp = tmp->next;
	return ((t_objects *)(tmp->content));
}

void	update_current_obj(t_minirt *data, int mode)
{
	int		len;

	len = ft_lstsize(*data->objects);
	if (mode == 0)
		data->current_obj = (data->current_obj + 1) % len;
	if (mode == 1)
		data->current_obj = (len + data->current_obj - 1) % len;
}

void	move_on_objects(t_minirt *data, int keysysm)
{
	t_objects	*node;

	if (keysysm == XK_n)
	{
		printf("Select next object :\n");
		update_current_obj(data, 0);
	}
	if (keysysm == XK_p)
	{
		printf("Select previous object :\n");
		update_current_obj(data, 1);
	}
	node = get_node(data, data->current_obj);
	print_object(node);
}
