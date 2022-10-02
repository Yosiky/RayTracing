/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:25:22 by eestelle          #+#    #+#             */
/*   Updated: 2022/10/02 16:26:15 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_sphere    *sphere_create(t_vector3 a, double r, uint color, uint specular, double ref)
{
    t_sphere    *res = (t_sphere *)malloc(sizeof(t_sphere));

    if (res == NULL)
        return (NULL);
    res->center = a;
    res->r = r;
    res->color = color;
    res->specular = specular;
    res->reflective = ref;
    return (res);
}

t_eelist    *ee_list_create(void *data)
{
    t_eelist    *res = (t_eelist *)malloc(sizeof(t_eelist));

    if (res == NULL)
        return (NULL);
    res->next = NULL;
    res->data = data;
    return (res);
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

    t_eelist    *test = ee_list_create((void *)sphere_create((t_vector3){0, -1, 3}, 1, 0x00ff0000, 500, 0.2));
    test->next = ee_list_create((void *)sphere_create((t_vector3){2, 0, 4}, 1, 0x000000ff, 500, 0.3));
    test->next->next = ee_list_create((void *)sphere_create((t_vector3){-2, 0, 4}, 1, 0x0000ff00, 10, 0.4));
    test->next->next->next = ee_list_create((void *)sphere_create((t_vector3){0, -5001, 0}, 5000, 0x00ffff00, 1000, 0.5));

    t_work_figure   functions = {intersect_ray_sphere, get_color_sphere, get_normal_sphere, get_specular_sphere, get_reflect_sphere};

    t_light ambient = {AMBIENT, 0.2, {0, 0, 0}};
    t_light point = {POINT, 0.6, {2, 1, 0}};
    t_light derectional = {DERECTIONAL, 0.2, {1, 4, 4}};

    vector3_normalized(&derectional.position);
    t_eelist   *test_light = ee_list_create(&ambient);
    test_light->next = ee_list_create(&point);
    test_light->next->next = ee_list_create(&derectional);
    /* t_eelist    *test_light = ee_list_create(&ambient); */
    /* t_eelist *test_light = ee_list_create(&point); */
    /* t_eelist *test_light = ee_list_create(&derectional); */

    get_light_all(test_light);

/* void    draw_on_img(t_image *img, t_eelist *lst, t_work_figure *funcs) */
    draw_on_img(ptr_image, test, &functions);
    mlx_put_image_to_window(ptr_mlx, ptr_window->win, ptr_image->img, 0, 0);
    free(test->data);
    free(test);
	mlx_loop(ptr_mlx);
    destroy_window(ptr_mlx, ptr_window);
    destroy_image(ptr_mlx, ptr_image);
    return (0);
}

