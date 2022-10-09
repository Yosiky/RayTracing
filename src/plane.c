#include "plane.h"
# define NULL (void *)0

double   intersect_ray_plane(t_vector3 *restrict o, t_vector3 *restrict d,
        void *data)
{
    t_plane   *plane = (t_plane *)data;
    t_vector3   *some = d;
    double          res;
    double          dot = vector3_dot(&plane->n, d);
    t_vector3       v;
    vector3_minus(&v, &plane->a, o);
    double          lenght = vector3_dot(&plane->n, &v);
    res = INFINITY;
    res = fmin(lenght / dot, res);
    return (res);
}

void    get_normal_plane(t_vector3 *restrict res, t_vector3 *restrict a,
        void *data)
{
    t_plane *plane = (t_plane *)data;
    
    *res = plane->n;
}
