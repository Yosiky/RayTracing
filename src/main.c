/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:25:22 by eestelle          #+#    #+#             */
/*   Updated: 2022/10/02 20:04:48 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void    create_sphere(t_object *elem, t_vector3 c, uint r, uint color, uint specular, double ref)
{
    elem->type = 0;
    elem->color = color;
    elem->specular = specular;
    elem->reflective = ref;
    elem->obj.sphere = (t_sphere *)malloc(sizeof(t_sphere));
    elem->obj.sphere->r = r;
    elem->obj.sphere->center = c;
}



int main(void)
{
    t_mlx *ptr_mlx = mlx_init();
    t_window    *ptr_window;
    t_image     *ptr_image;

    if (ptr_mlx == NULL)
        ee_error(1, "Can't init mlx");
    ptr_window = create_window(ptr_mlx, WINDOW_X, WINDOW_Y, WINDOW_NAME);
    ptr_image = create_image(ptr_mlx, IMG_X, IMG_Y);

    t_light ambient = {AMBIENT, 0.2, {0, 0, 0}};
    t_light point = {POINT, 0.6, {2, 1, 0}};
    t_light derectional = {DERECTIONAL, 0.2, {1, 4, 4}};
    t_light *light[] = {&ambient, &point, &derectional, NULL};
    t_object    *figures = (t_object *)malloc(sizeof(t_object) * 5);

    figures[4].type = -1;
    create_sphere(&figures[0], (t_vector3){0, -1, 3}, 1, 0x00ff0000, 500, 0.2);
    create_sphere(&figures[1], (t_vector3){2, 0, 4}, 1, 0x000000ff, 500, 0.3);
    create_sphere(&figures[2], (t_vector3){-2, 0, 4}, 1, 0x0000ff00, 10, 0.4);
    create_sphere(&figures[3], (t_vector3){0, -5001, 0}, 5000, 0x00ffff00, 1000, 0.5);
    vector3_normalized(&derectional.position);
    get_light_all(light);
    draw_on_img(ptr_image, figures);
    mlx_put_image_to_window(ptr_mlx, ptr_window->win, ptr_image->img, 0, 0);
    mlx_loop(ptr_mlx);
    destroy_window(ptr_mlx, ptr_window);
    destroy_image(ptr_mlx, ptr_image);
    return (0);
}

