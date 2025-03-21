/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:52:44 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/21 13:40:33 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



int	pars_sphere(t_minirt *data, char **arr)
{
	t_sphere	*sp;
	t_list		*new;

	if (arr_size(arr) != 4)
		return (ft_putstr_fd(SP_FORMAT, 2), EXIT_FAILURE);
	sp = malloc(sizeof(t_sphere));
	if (!sp)
		return (perror("malloc"), EXIT_FAILURE);
	sp->diam = ft_atof(arr[2]);
	if (sp->diam <= 0)
		return (free(sp), ft_puttr_fd(DIAM_ERROR, 2), ft_putstr_fd("sphere\n", 2), EXIT_FAILURE);
	sp->center = get_point(arr[1]);
	if (!sp->center)
		return (free(sp), ft_puttr_fd("sphere\n", 2), EXIT_FAILURE);
	sp->color = get_color(arr[3]);
	if (!sp->color)
		return (free(sp->center), free(sp), ft_putstr_fd("sphere\n", 2), EXIT_FAILURE);
	new = ft_lstnew(sp);
	if (!new)
		return (perror("malloc"), free(sp->center), free(sp->color), free(sp), EXIT_FAILURE);
	ft_lstadd_back(data->objects, new);
	return (EXIT_SUCCESS);
}

int	pars_plane(t_minirt *data, char **arr);

int	pars_cylindre(t_minirt *data, char **arr);