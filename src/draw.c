#include "miniRT.h"

typedef struct s_some_struct
{
    t_object    *ptr;
    double      value;
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

static t_some_struct    closestIntersection(t_vector3 *o, t_vector3 *d, t_object *objects, char flag)
{
    double      res;
    double      min_value;
    t_object    *ptr_obj;

    ptr_obj = NULL;
    res = INFINITY;
    while (objects->type != -1)
    {
        min_value = intersect_ray(o, d, objects);
        if (min_value < res)
        {
            res = min_value;
            ptr_obj = objects;
            if (flag)
                return ((t_some_struct){ptr_obj, res});
        }
        ++objects;
    }
    return ((t_some_struct){ptr_obj, res});
}

static double    compute_lighting(t_vector3 *p, t_vector3 *n, t_vector3 *v, uint s, t_object *objects)
{
    static t_light      **light = NULL;
    static int          indx;
    static double       intensity;
    static double       max;
    static t_vector3    l;
    double       n_dot_l;
    t_vector3           len;

    intensity = 0;
    indx = -1;
    if (light == NULL)
        light = get_light_all(NULL);
    while (light[++indx] != NULL)
    {
        if (light[indx]->type == AMBIENT)
            intensity += light[indx]->intensity;
        else 
        {
            if (light[indx]->type == POINT)
            {
                vector3_minus(&l, &(light[indx]->position), p);
                vector3_normalized(&l);
                max = 1;
                vector3_minus(&len, p, &(light[indx]->position));
            }
            else
            {
                l = light[indx]->position;
                max = INFINITY;
            }
            t_some_struct   va = closestIntersection(p, &l, objects, 1);
            if (va.ptr != NULL && ((light[indx]->type == POINT && vector3_length(&len) > va.value) || light[indx]->type == DERECTIONAL))
                continue ;
            n_dot_l = vector3_dot(n, &l);
            if (n_dot_l < EPS)
                n_dot_l *= -1; // ?????
            if (n_dot_l > EPS)
                intensity = fmin(1, intensity + light[indx]->intensity * n_dot_l);
            if (s != -1)
            {
                t_vector3 R;
                t_vector3 some;

                vector3_mul(&some, n, 2 * vector3_dot(n, &l));
                vector3_minus(&R, &some, &l);
                double r_dot_v = vector3_dot(&R, v);
                if (r_dot_v > 0)
                    intensity = fmin(1, intensity + light[indx]->intensity * pow(r_dot_v / (vector3_length(&R) * vector3_length(v)), s));
            }
        }
    }
    return (intensity);
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

static uint trace_ray(t_vector3 *o, t_vector3 *d, t_object *objects, int depth)
{
    t_vector3   p;
    t_vector3   n;
    double       min;
    t_some_struct res;
    uint        local_color;

    res = closestIntersection(o, d, objects, 0);
    if (res.ptr == NULL)
        return (COLOR_BACKGROUND);
    t_vector3 arr = {o->x + res.value * d->x, o->y + res.value * d->y, o->z + res.value * d->z};
    set_coordinates(&p, arr);
    get_normal(&n, &p, res.ptr);// todo
    vector3_mul(d, d, -1);
    local_color = color_transform(res.ptr->color, compute_lighting(&p, &n, d, res.ptr->specular, objects));
    double  r = res.ptr->reflective;
    if (depth <= 0 || r <= EPS)
        return (local_color);
    t_vector3 vec_r = reflect_ray(d, &n);
    vector3_normalized(&vec_r);
    uint reflect_color = trace_ray(&p, &vec_r, objects, depth - 1);
    return (get_right_color(local_color, reflect_color, r));
}

void    draw_on_img(t_image *img, t_object *objects)
{
    int         x;
    int         y;
    int         width_x = img->x / 2;
    int         width_y = img->y / 2;
    uint        color;
    t_vector3   d;

    y = -width_y;
    while (y < width_y)
    {
        x = -width_x;
        while (x < width_x)
        {
            set_coordinates(&d, (t_vector3){ (double)(x) * 1 / WINDOW_X, (double)(y) * 1 / WINDOW_Y, 1});
            rotate(&d, 0, 0, 0);
            color = trace_ray(get_viewer(NULL), &d, objects, 0/*RECURSIVE_DEPTH*/);
            ee_mlx_pixel_put(img, width_x + x, width_y - y, color);
            ++x;
        }
        ++y;
    }
}
