/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:25:22 by eestelle          #+#    #+#             */
/*   Updated: 2022/09/10 15:59:27 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(void)
{
    const t_mlx *ptr_mlx = mlx_init();
    t_window    *ptr_indow;
    t_image     *ptr_image;

    if (mlx == NULL)
        ee_error(1, "Can't init mlx");
    ptr_window = create_window(ptr_mlx, WINDOW_X, WINDOW_Y, WINDOW_NAME);
    ptr_image = create_image(ptr_mlx, IMG_X, IMG_Y);
    
    destroy_window(ptr_mlx, ptr_window);
    destroy_image(ptr_mlx, ptr_image);
    return (0);
}

