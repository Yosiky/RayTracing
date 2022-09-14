#include "miniRT.h"

static uint    trace_ray(t_vector3 *o, t_vector3 *d, t_vector3 minimum, t_eelist *lst, t_work_figure *funcs)
{
    t_vector3   min;
    float       res;
    t_eelist    *ptr_obj;

    ptr_obj = NULL;
    res = INT_MAX;
    while (lst != NULL)
    {
        min = funcs->intersect_ray(o, d, lst);
        /* printf("%lf %lf\n", min.x, min.y); */
        if (min.x < res && minimum.x < min.x && min.x < minimum.y)
        {
            res = min.x;
            ptr_obj = lst;
        }
        if (min.y < res && minimum.y < min.x && min.y < minimum.y)
        {
            res = min.y;
            ptr_obj = lst;
        }
        lst = lst->next;
    }
    /* printf("%u\n", funcs->get_color(ptr_obj)); */
    if (ptr_obj == NULL)
        return (COLOR_BACKGROUND);
    return (funcs->get_color(ptr_obj));
}

void    draw_on_img(t_image *img, t_eelist *lst, t_work_figure *funcs)
{
    int         x;
    int         y;
    int         width_x = img->x / 2;
    int         width_y = img->y / 2;
    uint        color;
    t_vector3   o;
    t_vector3   d;


    set_coordinates(&o, (float []){0, 0, 0});
    y = -width_y;
    while (y < width_y)
    {
        x = -width_x;
        while (x < width_x)
        {
            set_coordinates(&d, (float []){ (float)x * 1 / WINDOW_X, (float)y * 1 / WINDOW_Y, 1});
            color = trace_ray(&o, &d, (t_vector3){1, INT_MAX, 0}, lst, funcs);
            ee_mlx_pixel_put(img, (x++) + width_x, -y + width_y, color);
        }
        ++y;
    }
}
