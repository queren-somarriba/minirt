/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:14:42 by qsomarri          #+#    #+#             */
/*   Updated: 2025/03/28 16:53:04 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Chaque objet a une formule mathématique permettant de tester une intersection avec un rayon.
// 🔵 Intersection avec une sphère

// Équation d’une sphère centrée en C(xc,yc,zc)C(xc​,yc​,zc​) de rayon RR :
// (x−xc)2+(y−yc)2+(z−zc)2=R2
// (x−xc​)2+(y−yc​)2+(z−zc​)2=R2

// En remplaçant x,y,zx,y,z par les coordonnées du rayon :
// O+tD
// O+tD

// On obtient une équation quadratique :
// at2+bt+c=0
// at2+bt+c=0

// Avec :

//     a=D⋅Da=D⋅D (produit scalaire de la direction du rayon)

//     b=2×(O−C)⋅Db=2×(O−C)⋅D

//     c=(O−C)⋅(O−C)−R2c=(O−C)⋅(O−C)−R2

// On résout avec le discriminant :
// Δ=b2−4ac
// Δ=b2−4ac

//     Si Δ<0Δ<0 → Pas d’intersection.

//     Si Δ=0Δ=0 → Une seule intersection.

//     Si Δ>0Δ>0 → Deux intersections (prendre la plus proche tt > 0).

// 💡 
// Intersection Rayon-Sphère

// int intersect_sphere(t_ray ray, t_sphere sphere, float *t) {
//     t_vector oc = subtract(ray.origin, sphere.center);
//     float a = dot(ray.direction, ray.direction);
//     float b = 2.0f * dot(oc, ray.direction);
//     float c = dot(oc, oc) - sphere.radius * sphere.radius;
//     float delta = b * b - 4 * a * c;

//     if (delta < 0)
//         return (0);
//     *t = (-b - sqrt(delta)) / (2.0 * a);
//     return (1);
// }

t_point	inter_sphere(t_sphere sp, t_ray ray)
{
	
}