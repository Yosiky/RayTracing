/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:18:56 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/28 22:42:17 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

double	intersect_ray(t_vector3 *o, t_vector3 *d, t_object *obj)
{
	static t_intersec_ray	func[] = {intersect_ray_sphere,
		intersect_ray_plane, intersect_ray_cylinder};

	return (func[obj->type](o, d, obj->u_obj.start));
}

void	get_normal(t_vector3 *dst, t_vector3 *one, t_object *obj)
{
	static t_get_normal	func[] = {get_normal_sphere,
		get_normal_plane, get_normal_cylinder};

	func[obj->type](dst, one, obj->u_obj.start);
}
