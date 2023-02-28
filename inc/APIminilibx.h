/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APIminilibx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:26:16 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/28 22:34:01 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APIMINILIBX_H
# define APIMINILIBX_H

# include "mlx.h"
# if __APPLE__
#  include <stdlib.h>
# else
#  include "malloc.h"
# endif

typedef unsigned int	t_uint;
typedef void*			t_mlx;

typedef struct s_image
{
	void	*img;
	t_uint	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_uint	x;
	t_uint	y;
} __attribute__((__packed__, __aligned__(8)))	t_image;

typedef struct s_window
{
	void		*win;
	int			x;
	int			y;
	const char	*name;
} __attribute__((__packed__, __aligned__(8)))	t_window;

t_window	*create_window(t_mlx mlx, int x, int y, char *str);
void		destroy_window(t_mlx mlx, t_window *win);
t_image		*create_image(t_mlx mlx, t_uint x, t_uint y);
void		destroy_image(t_mlx mlx, t_image *img);
void		ee_mlx_pixel_put(t_image *img, t_uint x, t_uint y, t_uint color);

#endif
