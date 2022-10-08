#include "plane.h"
# define NULL (void *)0

void    get_normal_plane(t_vector3 *restrict res, t_vector3 *restrict a,
        void *data);

double   intersect_ray_plane(t_vector3 *restrict o, t_vector3 *restrict d,
        void *data)
{
    t_plane   *plane = (t_plane *)data;
    double          res;
    get_normal_plane(&(plane->n), NULL, data);
    double          dot = vector3_dot(&plane->n, d);
    t_vector3       v;
    vector3_minus(&v, &plane->a, o);
    double          lenght = vector3_dot(&plane->n, &v);
    res = lenght / dot;
    return res;
}

void    get_normal_plane(t_vector3 *restrict res, t_vector3 *restrict a,
        void *data)
{
    t_plane *p = (t_plane *)data;
    t_vector3   c, b;

    vector3_minus(&c, &p->a, &p->b);
    vector3_minus(&b, &p->c, &p->b);

    t_vector3 normal = {c.z * b.y - c.y * b.z, c.x * b.z - c.z * b.x, c.y * b.x - c.x * b.y};
    vector3_normalized(res);
    *res = normal;
    p->n = normal;
}
