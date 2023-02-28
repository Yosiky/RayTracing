/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:36:14 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/27 23:36:37 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light	*get_light(t_light *arr)
{
	static t_light	*light;

	if (arr != NULL)
		light = arr;
	return (light);
}
