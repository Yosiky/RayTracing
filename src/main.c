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

void    ee_error(int code, const char *str);

int main(void)
{
    t_file *ptr_file;

    return (0);
}
