/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:03:38 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/28 23:06:26 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vector3.h"
# include <sys/types.h>
# include "math.h"
# include "limits.h"
# include "constants.h"

typedef struct s_sphere
{
	double		r;
	t_vector3	center;
} __attribute__((__packed__, __aligned__(8)))	t_sphere;

double	intersect_ray_sphere(t_vector3 *restrict o, t_vector3 *restrict d,
			void *data);
void	get_normal_sphere(t_vector3 *restrict res, t_vector3 *restrict a,
			void *data);

#endif
