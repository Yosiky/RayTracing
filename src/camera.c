/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:25:17 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/27 23:25:59 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_vector3	*get_viewer(t_vector3 *ptr)
{
	static t_vector3	*obj = NULL;

	if (ptr != NULL)
		obj = ptr;
	return (obj);
}

t_camera	*get_camera(t_camera *ptr)
{
	static t_camera	*obj;

	if (ptr != NULL)
	{
		obj = ptr;
		get_viewer(&obj->coordinate);
		get_rotate_y(&obj->rotate_x);
		get_rotate_x(&obj->rotate_y);
	}
	return (obj);
}

int	*get_rotate_x(int *ptr)
{
	static int	*rotate;

	if (ptr != NULL)
		rotate = ptr;
	return (rotate);
}

int	*get_rotate_y(int *ptr)
{
	static int	*rotate;

	if (ptr != NULL)
		rotate = ptr;
	return (rotate);
}
