#include "miniRT.h"

t_vector3   intersect_ray_sphere(t_vector3 *o, t_vector3 *d, t_eelist *lst)
{
    const t_sphere  *ptr_sphere = (const t_sphere *)lst->data;
    t_vector3       oc;
    float           k[4];

    vector3_minus(&oc, o, &ptr_sphere->center);
    k[0] = vector3_dot(d, d);
    k[1] = 2 * vector3_dot(&oc, d);
    k[2] = vector3_dot(&oc, &oc) - ptr_sphere->r * ptr_sphere->r;
    k[3] = sqrt(k[1] * k[1] - 4 * k[0] * k[2]);
    if (k[3] < 0 + EPS)
        return ((t_vector3){INT_MAX, INT_MAX, 0});
    return ((t_vector3){(-k[1] + k[3]) / (2 * k[0]), (-k[1] - k[3]) / (2 * k[0]), 0});
}

uint    get_color_sphere(t_eelist *lst)
{
    return (((t_sphere *)(lst->data))->color);
}
