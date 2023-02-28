/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:03:20 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/28 23:03:21 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include <sys/types.h>
# include "sphere.h"
# include "plane.h"
# include "cylinder.h"

typedef double	(*t_intersec_ray)(t_vector3 *, t_vector3 *, void *);
typedef void	(*t_get_normal)(t_vector3 *, t_vector3 *, void *);

enum e_TYPE_OBJECT
{
	OBJ_NONE = -1,
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
};

typedef struct s_object
{
	int			type;
	uint32_t	color;
	int			specular;
	double		reflective;
	union
	{
		void		*start;
		t_sphere	*sphere;
		t_plane		*plane;
		t_cylinder	*cylinder;
	}	u_obj;
} __attribute__((__packed__, __aligned__(8)))	t_object;

double	intersect_ray(t_vector3 *o, t_vector3 *d, t_object *obj);
void	get_normal(t_vector3 *dst, t_vector3 *one, t_object *obj);

#endif
