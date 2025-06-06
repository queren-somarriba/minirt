/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:00:10 by qsomarri          #+#    #+#             */
/*   Updated: 2025/04/24 15:08:25 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}		t_vector;

typedef struct s_ray
{
	t_vector	p;
	t_vector	v;
}		t_ray;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_amb_light
{
	float	ratio;
	t_color	*color;
}		t_amb_light;

typedef struct s_cam
{
	t_vector	*p;
	t_vector	*v;
	t_vector	forw;
	t_vector	right;
	t_vector	up;
	int			fov;
}		t_cam;

typedef struct s_light
{
	t_vector	*p;
	float		brightness;
}		t_light;

typedef struct s_sphere
{
	t_vector	*center;
	float		diam;
	t_color		*color;
}		t_sphere;

typedef struct s_plane
{
	t_vector	*point;
	t_vector	*axis;
	t_color		*color;
}		t_plane;

typedef struct s_cylinder
{
	t_vector	*center;
	t_vector	*axis;
	float		diam;
	float		height;
	t_color		*color;
}		t_cylinder;

typedef enum e_obj_id
{
	AMB,
	CAM,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}		t_obj_id;

typedef struct s_objects
{
	t_obj_id		type;
	int				index;
	void			*obj;
}		t_objects;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}		t_img;

typedef struct s_inter
{
	t_vector	p;
	t_color		c;
	float		dist;
	t_vector	normal;
	int			obj_index;
}		t_inter;

typedef struct s_minirt
{
	t_amb_light	*amb;
	t_cam		*cam;
	t_light		*light;	
	t_list		**objects;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	int			current_obj;
}		t_minirt;

#endif
