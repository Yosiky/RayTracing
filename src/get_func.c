/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:26:35 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/27 23:27:10 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_object	*get_object(t_object *ptr)
{
	static t_object	*obj = NULL;

	if (ptr != NULL)
		obj = ptr;
	return (obj);
}

t_image	*get_image(t_image *ptr)
{
	static t_image	*obj = NULL;

	if (ptr != NULL)
		obj = ptr;
	return (obj);
}

t_window	*get_window(t_window *ptr)
{
	static t_window	*obj = NULL;

	if (ptr != NULL)
		obj = ptr;
	return (obj);
}

t_mlx	*get_mlx(t_mlx *ptr)
{
	static t_mlx	*obj = NULL;

	if (ptr != NULL)
		obj = ptr;
	return (obj);
}
