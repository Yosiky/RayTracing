/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */ /*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:25:22 by eestelle          #+#    #+#             */
/*   Updated: 2022/10/08 20:58:24 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

void    create_plane(t_object *elem, t_vector3 a, t_vector3 b, t_vector3 c, uint color, uint specular, double ref)
{
    elem->type = 1;
    elem->color = color;
    elem->obj.plane = (t_plane *)malloc(sizeof(t_plane));
    elem->obj.plane->a = a;
    elem->obj.plane->b = b;
    elem->obj.plane->c = c;
    elem->specular = specular;
    elem->reflective = ref;
    t_vector3   one, two;

    vector3_minus(&one, &a, &b);
    vector3_minus(&two, &c, &b);

    t_vector3 normal = {one.z * two.y - one.y * two.z, one.x * two.z - one.z * two.x, one.y * two.x - one.x * two.y};
    /* vector3_mul(&normal, &normal, -1); */
    vector3_normalized(&normal);
    elem->obj.plane->n = normal;
}

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

t_vector3    *get_viewer(t_vector3 *ptr)
{
    static t_vector3 obj = {0, 0, 0};

    if (ptr != NULL)
        obj = *ptr;
    return (&obj);
}

t_object    *get_object(t_object *ptr)
{
    static t_object *obj = NULL;

    if (ptr != NULL)
        obj = ptr;
    return (obj);
}

t_image    *get_image(t_image *ptr)
{
    static t_image *obj = NULL;

    if (ptr != NULL)
        obj = ptr;
    return (obj);
}

t_window    *get_window(t_window *ptr)
{
    static t_window *obj = NULL;

    if (ptr != NULL)
        obj = ptr;
    return (obj);
}

t_mlx    *get_mlx(t_mlx *ptr)
{
    static t_mlx *obj = NULL;

    if (ptr != NULL)
        obj = ptr;
    return (obj);
}

int ee_exit(void)
{
    exit(0);
}

void    init_hook(t_window *ptr_window)
{
    mlx_key_hook(ptr_window->win, event_move, NULL);
    mlx_hook(ptr_window->win, 17, 0, ee_exit, NULL);
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
    init_hook(ptr_window);

    t_light ambient = {AMBIENT, 0.2, {0, 0, 0}};
    t_light point = {POINT, 0.6, {2, 1, 0}};
    t_light derectional = {DERECTIONAL, 0.2, {1, 4, 4}};
    t_light *light[] = {&ambient, &point, &derectional, NULL};
    t_object    *figures = (t_object *)malloc(sizeof(t_object) * 6);

    get_object(figures);
    get_image(ptr_image);
    get_window(ptr_window);
    get_mlx(ptr_mlx);
    create_sphere(&figures[0], (t_vector3){0, -1, 3}, 1, 0x00ff0000, 500, 0.2);
    create_sphere(&figures[1], (t_vector3){2, 0, 4}, 1, 0x000000ff, 500, 0.3);
    create_sphere(&figures[2], (t_vector3){-2, 0, 4}, 1, 0x0000ff00, 10, 1);
    /* create_sphere(&figures[3], (t_vector3){0, -5001, 0}, 5000, 0x00ffff00, 1000, 0.5); */
    create_plane(&figures[3], (t_vector3){-2, -1, -2}, (t_vector3){0, -1, 0}, (t_vector3){1, -1, 10}, 0x00ffff00, 1000, 0);
    create_plane(&figures[4], (t_vector3){-4, 1, 10}, (t_vector3){-4, 0, 0}, (t_vector3){-4, 0, 4}, 0x00ff00ff, 1000, 0.5);
    figures[5].type = -1;
    vector3_normalized(&derectional.position);
    get_light_all(light);
    draw_on_img(ptr_image, figures);
    mlx_put_image_to_window(ptr_mlx, ptr_window->win, ptr_image->img, 0, 0);
    mlx_loop(ptr_mlx);
    destroy_window(ptr_mlx, ptr_window);
    destroy_image(ptr_mlx, ptr_image);
    return (0);
}
