#include "plane.h"

double   intersect_ray_plane(t_vector3 *restrict o, t_vector3 *restrict d,
        void *data)
{
    const t_plane   *plane = (t_plane *)data;
    double          res;

    res = INFINITY;
    return res;
}

void    get_normal_plane(t_vector3 *restrict res, const t_vector3 *restrict a,
        void *data)
{

}
