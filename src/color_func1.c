/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:27:48 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/27 23:31:05 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static t_color	*translate(t_color *res, uint32_t a)
{
	int	i;

	i = 4;
	while (i-- > 0)
	{
		res->arr[i] = (double)(a & MASK_BYTE) / 255;
		a >>= 8;
	}
	return (res);
}

t_color	*color_create(t_color *res, uint32_t a, double intensity)
{
	int	i;

	translate(res, a);
	i = -1;
	while (++i < 4)
		res->arr[i] = fmin(1, res->arr[i] * intensity);
	return (res);
}

t_color	*color_add(t_color *res, t_color *a, t_color *b)
{
	int	i;

	i = -1;
	while (++i < 4)
		res->arr[i] = fmin(1, a->arr[i] + b->arr[i]);
	return (res);
}

t_color	*color_mul(t_color *res, t_color *a, t_color *b)
{
	int	i;

	i = -1;
	while (++i < 4)
		res->arr[i] = fmin(1, a->arr[i] * b->arr[i]);
	return (res);
}

uint32_t	color_double_int(t_color *color)
{
	uint32_t	res;
	int			i;

	res = 0;
	i = -1;
	while (++i < 4)
	{
		res <<= 8;
		res |= (t_uchar)(color->arr[i] * 254);
	}
	return (res);
}
