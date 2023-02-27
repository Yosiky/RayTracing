/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:30:48 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/27 23:30:49 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color_init(double arr[4])
{
	t_color	res;

	res.arr[0] = arr[0];
	res.arr[1] = arr[1];
	res.arr[2] = arr[2];
	res.arr[3] = arr[3];
	return (res);
}