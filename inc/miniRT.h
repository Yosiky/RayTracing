/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:54:31 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/28 22:58:02 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "constants.h"
# include "APIminilibx.h"
# include "vector3.h"
# include "light.h"
# include "parser.h"
# include "libft.h"
# include "constants.h"
# include "camera.h"
# include "color.h"

# include "objects.h"
# include <stdint.h>
# include <limits.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define WINDOW_NAME "miniRT"
# define WINDOW_X 1000
# define WINDOW_Y 1000
# define IMG_X 1000
# define IMG_Y 1000
# define SCREEN_IMG_X WINDOW_X
# define SCREEN_IMG_Y WINDOW_Y

# define RECURSIVE_DEPTH 5
# define COLOR_BACKGROUND   0X00000000

void		draw_on_img(t_image *img, t_object *objects);
int			event_move(int key, void *arg);
void		rotate(t_vector3 *d, int flag);
t_object	*get_object(t_object *ptr);
t_image		*get_image(t_image *ptr);
t_window	*get_window(t_window *ptr);
t_mlx		*get_mlx(t_mlx *ptr);
void		print_obj(t_object *ptr);
void		print_camera(t_camera *obj);
t_uint		ee_color_parse(char *str);
void		parse_data(t_file *ptr);
void		create_light(const char *str, void *dst);
void		create_camera(const char *str, void *dst);
void		create_sphere(const char *str, void *dst);
void		create_plane(const char *str, void *dst);
void		create_cylinder(const char *str, void *dst);

#endif
