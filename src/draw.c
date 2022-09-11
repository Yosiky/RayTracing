#include "miniRT.h"

uint    trace_ray(t_vector3 *o, t_vector3 *d, t_vector3 minimum, t_eelist *lst, t_work_figure *funcs)
{
    t_vector3   min;
    float       res;
    t_eelist    *ptr_obj;

    ptr_obj = NULL;
    res = INT_MAX;
    while (lst != NULL)
    {
        min = funcs->intersect_ray(o, d, lst);
        if (min.x < res + EPS && min.x > minimum.x && min.x < minimum.y)
        {
            res = min.x;
            ptr_obj = lst;
        }
        if (min.y < res + EPS && min.y > minimum.x && min.y < minimum.y)
        {
            res = min.y;
            ptr_obj = lst;
        }
    }
    if (ptr_obj == NULL)
        return (COLOR_BACKGROUND);
    return (funcs->get_color(ptr_obj));
}

void    draw_on_img(t_image *img, t_eelist *lst, t_work_figure *funcs)
{
    uint        x;
    uint        y;
    uint        color;
    t_vector3   o;
    t_vector3   d;

    set_coordinates(&o, (float []){0, 0, 0});
    x = 0;
    while (x < img->x)
    {
        y = 0;
        while (y < img->y)
        {
            set_coordinates(&d, (float []){ x / WINDOW_X * SCREEN_IMG_X, y / WINDOW_Y * SCREEN_IMG_Y, 1});
            color = trace_ray(&o, &d, (t_vector3){1, INT_MAX, 0}, lst, funcs);
            ee_mlx_pixel_put(img, x, y++, color);
        }
        ++x;
    }
}
