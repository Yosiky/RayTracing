/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:04:17 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/28 23:05:20 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector3.h"

typedef struct s_camera
{
	t_vector3		coordinate;
	t_vector3		normal;
	int				rotate_x;
	int				rotate_y;
	unsigned int	view;
}	t_camera;

t_camera	*get_camera(t_camera *obj);
t_vector3	*get_viewer(t_vector3 *ptr);
int			*get_rotate_x(int *ptr);
int			*get_rotate_y(int *ptr);

#endif
