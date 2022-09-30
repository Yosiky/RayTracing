#include "miniRT.h"

typedef struct s_some_struct
{
    void *ptr;
    double   value;
}   t_some_struct;

t_vector3   reflect_ray(t_vector3 *r, t_vector3 *n)
{
    t_vector3   res;

    vector3_mul(&res, n, vector3_dot(n, r) * 2);
    vector3_minus(&res, &res, r);
    return (res);
}

static uint color_transform(uint color, double intensity)
{
    union {
        uint            color;
        unsigned char   c[4];
    }   res;
    int i;

    res.color = color;
    i = -1;
    while (++i < 4)
    {
        double   value = res.c[i];
        res.c[i] = (unsigned char)(value * intensity);
    }
    return (res.color);
}

static t_some_struct    closestIntersection(t_vector3 *o, t_vector3 *d, t_eelist *lst, t_work_figure *funcs)
{
    double   res;
    double   min_value;
    void        *ptr_obj;

    ptr_obj = NULL;
    res = INFINITY;
    while (lst != NULL)
    {
        min_value = funcs->intersect_ray(o, d, lst->data);
        if (min_value < res)
        {
            res = min_value;
            ptr_obj = lst->data;
        }
        lst = lst->next;
    }
    return ((t_some_struct){ptr_obj, res});
}

static double    compute_lighting(t_vector3 *p, t_vector3 *n, t_vector3 *v, uint s, t_eelist *lst, t_work_figure *funcs, t_eelist *lst_figure)
{
    t_vector3   l;
    double       n_dot_l;
    double       res;
    uint        type;
    double       max;

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
                max = 1;
            }
            else
            {
                l = ((t_light *)lst->data)->position;
                max = INFINITY;
            }
            t_some_struct   some = closestIntersection(p, &l, lst_figure, funcs);
            if (some.ptr != NULL)
            {
                lst = lst->next;
                continue ;
            }
            n_dot_l = vector3_dot(n, &l);
            if (n_dot_l > 0)
                res += ((t_light *)lst->data)->intensity * n_dot_l;
            if (s != -1)
            {
                t_vector3 R;

                vector3_mul(n, n, 2 * vector3_dot(n, &l));
                vector3_minus(&R, n, &l);
                double r_dot_v = vector3_dot(&R, v);
                if (r_dot_v > 0)
                    res = fmin(1, res + ((t_light *)lst->data)->intensity * pow(r_dot_v / (vector3_length(&R) * vector3_length(v)), s));
            }
        }
        lst = lst->next;
    }
    return (res);
}

uint    get_right_color(uint a, uint b, double c)
{
    union {
        uint            color;
        unsigned char   c[4];
    }   res, copy;
    uint i = 0;

    copy.color = b;
    res.color = a;
    i = -1;
    while (++i < 4)
    {
        double  value_two = copy.c[i];
        double  value = res.c[i];
        res.c[i] = value * (1 - c) + value_two * c;
    }
    return (res.color);
}

static uint trace_ray(t_vector3 *o, t_vector3 *d, t_eelist *lst, t_work_figure *funcs, int depth)
{
    t_vector3   p;
    t_vector3   n;
    double       min;
    t_some_struct res;
    uint        local_color;

    res = closestIntersection(o, d, lst, funcs);
    if (res.ptr == NULL)
        return (COLOR_BACKGROUND);
    t_vector3 arr = {o->x + res.value * d->x, o->y + res.value * d->y, o->z + res.value * d->z};
    set_coordinates(&p, arr);
    funcs->get_normal(&n, &p, res.ptr);
    vector3_mul(d, d, -1);
    local_color = color_transform(funcs->get_color(res.ptr), compute_lighting(&p, &n, d, funcs->get_specular(res.ptr), get_light_all(NULL), funcs, lst));
    double  r = funcs->get_reflect(res.ptr);
    if (depth < 0 || r <= EPS)
        return (local_color);
    t_vector3 vec_r = reflect_ray(d, &n);
    uint reflect_color = trace_ray(&p, &vec_r, lst, funcs, depth - 1);
    return (get_right_color(local_color, reflect_color, r));
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
            set_coordinates(&d, (t_vector3){ (double)(x) * 1 / WINDOW_X, (double)(y) * 1 / WINDOW_Y, 1});
            color = trace_ray(&o, &d, lst, funcs, RECURSIVE_DEPTH);
            ee_mlx_pixel_put(img, width_x + x, width_y - y, color);
            ++x;
            /* ee_mlx_pixel_put(img, (x++), y, color); */
        }
        ++y;
    }
}
