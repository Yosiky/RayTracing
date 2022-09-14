#include "miniRT.h"

static float    compute_lighting(t_vector3 *p, t_vector3 *n, t_eelist *lst)
{
    t_vector3   l;
    float       n_dot_l;
    float       res;
    uint        type;

    res = 0;
    while (lst)
    {
        type = get_light_type(lst->data);
        if (type == AMBIENT)
            res += ((t_light *)lst->data)->intensity;
        else 
        {
            if (type == POINT)
                vector3_minus(&l, &((t_light *)lst->data)->position, p);
            else
                l = ((t_light *)lst->data)->position;
            n_dot_l = vector3_dot(n, &l);
            if (n_dot_l > 0)
                res += ((t_light *)lst->data)->intensity * n_dot_l / (vector3_length(n) * vector3_length(&l));
        }
    }
    return (res);
}

static uint trace_ray(t_vector3 *o, t_vector3 *d, t_vector3 minimum, t_eelist *lst, t_work_figure *funcs)
{
    t_vector3   min;
    t_vector3   p;
    t_vector3   n;
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
    set_coordinates(&p, (float []){o->x + res * d->x, o->y + res * d->y, o->z + res * d->z});
    funcs->get_normal(&n, &p, ptr_obj);
    return (funcs->get_color(ptr_obj) * compute_lighting(&p, &n, get_light_all(NULL)));
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
