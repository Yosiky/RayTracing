/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:06:34 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/28 23:07:18 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vector3.h"
# include "stddef.h"

typedef unsigned int	t_uint;

enum	e_TYPE_LIGHT
{
	LIGHT_NONE = -1,
	LIGHT_AMBIENT,
	LIGHT_POINT,
	LIGHT_DERECTIONAL
};

typedef struct s_light
{
	enum e_TYPE_LIGHT	type;
	double				intensity;
	t_vector3			position;
	t_uint				color;
}	t_light;

t_light	*get_light(t_light *light);

#endif
