/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:25:22 by eestelle          #+#    #+#             */
/*   Updated: 2022/09/11 15:53:01 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(void)
{
    t_mlx *ptr_mlx = mlx_init();
    t_window    *ptr_window;
    t_image     *ptr_image;

    if (ptr_mlx == NULL)
        ee_error(1, "Can't init mlx");
    ptr_window = create_window(ptr_mlx, WINDOW_X, WINDOW_Y, WINDOW_NAME);
    ptr_image = create_image(ptr_mlx, IMG_X, IMG_Y);
    ee_mlx_pixel_put(ptr_image, 100, 100, 0xffffffff);
    for (int i = 0; i < IMG_X; ++i)
        for (int j = 0; j < IMG_Y; ++j)
            ee_mlx_pixel_put(ptr_image, i, j, 0x55555555);
    mlx_put_image_to_window(ptr_mlx, ptr_window->win, ptr_image->img, 0, 0);
	mlx_loop(ptr_mlx);
    destroy_window(ptr_mlx, ptr_window);
    destroy_image(ptr_mlx, ptr_image);
    return (0);
}

