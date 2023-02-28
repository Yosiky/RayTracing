/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:58:34 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/28 23:03:01 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "constants.h"
# include "vector3.h"
# include <sys/types.h>
# include "math.h"
# include "limits.h"

union	u_fast_vector3
{
	double		arr[3];
	t_vector3	point;
};

typedef struct s_plane
{
	t_vector3	point;
	t_vector3	normal;
} __attribute__((__packed__, __aligned__(8)))	t_plane;

double	intersect_ray_plane(t_vector3 *restrict o, t_vector3 *restrict d,
			void *data);
void	get_normal_plane(t_vector3 *restrict res,
			t_vector3 *restrict a, void *data);

#endif
