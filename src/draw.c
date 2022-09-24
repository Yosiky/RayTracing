#include "miniRT.h"

static uint color_transform(uint color, float intensity)
{
    union {
        uint            color;
        unsigned char   c[4];
    }   res;
    int i;

    res.color = color; //0xffffffff;
    i = -1;
    while (++i < 4)
    {
        float   value = res.c[i];
        res.c[i] = (unsigned char)(value * intensity);
    }
    return (res.color);
}

static float    compute_lighting(t_vector3 *p, t_vector3 *n, t_vector3 *v, uint s, t_eelist *lst)
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
            if (s != -1)
            {
                t_vector3 R;

                vector3_mul(n, n, 2 * vector3_dot(n, &l));
                vector3_minus(&R, n, &l);
                float r_dot_v = vector3_dot(&R, v);
                if (r_dot_v > 0)
                    res = fmin(1, res + ((t_light *)lst->data)->intensity * pow(r_dot_v / (vector3_length(&R) * vector3_length(v)), s));
            }
        }
        lst = lst->next;
    }
    return (res);
}

static uint trace_ray(t_vector3 *o, t_vector3 *d, t_eelist *lst, t_work_figure *funcs)
{
    t_vector3   p;
    t_vector3   n;
    float       min;
    float       res;
    void        *ptr_obj;

    ptr_obj = NULL;
    res = INFINITY;
    while (lst != NULL)
    {
        min = funcs->intersect_ray(o, d, lst->data);
        if (min < res)
        {
            res = min;
            ptr_obj = lst->data;
        }
        lst = lst->next;
    }
    if (ptr_obj == NULL)
        return (COLOR_BACKGROUND);
    t_vector3 arr = {o->x + res * d->x, o->y + res * d->y, o->z + res * d->z};
    set_coordinates(&p, arr);
    funcs->get_normal(&n, &p, ptr_obj);
    vector3_mul(d, d, -1);
    return (color_transform(funcs->get_color(ptr_obj), compute_lighting(&p, &n, d, funcs->get_specular(ptr_obj), get_light_all(NULL))));
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

    set_coordinates(&o, (t_vector3){0, 0, 0});
    y = -width_y;
    while (y < width_y)
    {
        x = -width_x;
        while (x < width_x)
        {
            set_coordinates(&d, (t_vector3){ (float)(x) * 1 / WINDOW_X, (float)(y) * 1 / WINDOW_Y, 1});
            color = trace_ray(&o, &d, lst, funcs);
            ee_mlx_pixel_put(img, width_x + x, width_y - y, color);
            ++x;
            /* ee_mlx_pixel_put(img, (x++), y, color); */
        }
        ++y;
    }
}
