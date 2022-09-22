#include "miniRT.h"

static uint color_transform(uint color, float intensity)
{
    union
    {
        uint            color;
        unsigned char   c[4];
    }   res;
    int i;

    res.color = color;
    i = -1;
    while (++i < 4)
        res.c[i] = (unsigned char)((float)res.c[i] * intensity);
    return (res.color);
}

static float    compute_lighting(t_vector3 *p, t_vector3 *n, t_eelist *lst)
{
    t_vector3   l;
    float       n_dot_l;
    float       res;
    uint        type;

    res = 0;
    while (lst)
    {
        type = get_light_type(lst);
        if (type == AMBIENT)
            res += ((t_light *)lst->data)->intensity;
        else 
        {
            if (type == POINT)
            {
                vector3_minus(&l, &((t_light *)lst->data)->position, p);
                vector3_normalized(&l);
            }
            else
                l = ((t_light *)lst->data)->position;
            n_dot_l = vector3_dot(n, &l);
            if (n_dot_l > 0)
                res += ((t_light *)lst->data)->intensity * n_dot_l;
        }
        lst = lst->next;
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
    return (color_transform(funcs->get_color(ptr_obj), compute_lighting(&p, &n, get_light_all(NULL))));
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
    y = 0;
    while (y < img->y)
    {
        x = 0;
        while (x < img->x)
        {
            set_coordinates(&d, (float []){ (float)(x - width_x) * 1 / WINDOW_X, (float)(-y + width_y) * 1 / WINDOW_Y, 1});
            //vector3_normalized(&d);
            color = trace_ray(&o, &d, (t_vector3){1, INT_MAX, 0}, lst, funcs);
            ee_mlx_pixel_put(img, (x++), y, color);
        }
        ++y;
    }
}
