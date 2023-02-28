/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:38:00 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/28 22:20:12 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

int	check_hight(t_cylinder *ptr, t_vector3 *o, t_vector3 *d, double t)
{
	t_vector3	a;

	vector3_mul(&a, d, t);
	vector3_plus(&a, o, &a);
	vector3_minus(&a, &a, &ptr->center);
	t = vector3_dot(&a, &ptr->normal);
	if (t < EPS)
		return (0);
	if (t > ptr->hight - EPS)
		return (0);
	return (1);
}

double	intersect_ray_cylinder(t_vector3 *restrict o, t_vector3 *restrict d,
			void *data)
{
	t_cylinder *const	ptr = (t_cylinder *)data;
	t_vector3			arr_vector3[3];
	double				res;
	double				k[5];

	vector3_minus(&arr_vector3[0], o, &ptr->center);
	vector3_cross(&arr_vector3[1], &arr_vector3[0], &ptr->normal);
	vector3_cross(&arr_vector3[1], d, &ptr->normal);
	k[0] = vector3_dot(&arr_vector3[1], &arr_vector3[1]);
	k[1] = vector3_dot(&arr_vector3[1], &arr_vector3[1]) * 2.;
	k[2] = vector3_dot(&arr_vector3[1], &arr_vector3[1]) - ptr->r * ptr->r;
	k[3] = k[1] * k[1] - 4. * k[0] * k[2];
	if (k[3] < EPS)
		return (INFINITY);
	res = INFINITY;
	k[3] = sqrt(k[3]);
	k[4] = (-k[1] + k[3]) / (2. * k[0]);
	if (EPS < k[4] && k[4] < INFINITY && check_hight(ptr, o, d, k[4]))
		res = fmin(k[4], res);
	k[4] = (-k[1] - k[3]) / (2. * k[0]);
	if (EPS < k[4] && k[4] < INFINITY && check_hight(ptr, o, d, k[4]))
		res = fmin(k[4], res);
	return (res);
}

int	check_point_on_cylinder(t_cylinder *ptr, t_vector3 *point)
{
	t_vector3	op;
	double		length;

	vector3_minus(&op, point, &ptr->center);
	length = vector3_dot(&op, &ptr->normal);
	if (length < EPS)
		return (1);
	if (length > ptr->hight - EPS)
		return (2);
	return (0);
}

void	get_normal_cylinder(t_vector3 *restrict res,
			t_vector3 *restrict a, void *data)
{
	t_cylinder *const	ptr = (t_cylinder *)data;
	t_vector3			o;
	t_vector3			cp;
	double				pn_len;

	vector3_minus(&cp, a, &ptr->center);
	pn_len = vector3_dot(&ptr->normal, &cp);
	vector3_mul(&o, &ptr->normal, pn_len);
	vector3_plus(&o, &o, &ptr->center);
	vector3_minus(res, a, &o);
	vector3_normalized(res);
}
