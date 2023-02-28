/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:59:43 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/28 23:01:18 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vector3.h"
# include "constants.h"

typedef struct s_cylinder
{
	double		r;
	double		hight;
	t_vector3	center;
	t_vector3	normal;
} __attribute__((__packed__, __aligned__(8)))	t_cylinder;

double	intersect_ray_cylinder(t_vector3 *restrict o, t_vector3 *restrict d,
			void *data);
void	get_normal_cylinder(t_vector3 *restrict res,
			t_vector3 *restrict a, void *data);

#endif
