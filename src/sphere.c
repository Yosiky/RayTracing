#include "sphere.h"

uint    get_color_sphere(void *data)
{
    return (((t_sphere *)data)->color);
}

float   intersect_ray_sphere(t_vector3 *o, t_vector3 *d, void *data)
{
    const t_sphere  *ptr_sphere = (t_sphere *)data;
    t_vector3       oc;
    float           k[6];
    float res = INFINITY;

    vector3_minus(&oc, o, &ptr_sphere->center);
    k[0] = vector3_dot(d, d);
    k[1] = 2 * vector3_dot(&oc, d);
    k[2] = vector3_dot(&oc, &oc) - ptr_sphere->r * ptr_sphere->r;
    k[3] = k[1] * k[1] - 4 * k[0] * k[2];
    if (k[3] < 0)
        return (INFINITY);
    k[3] = sqrt(k[3]);
    k[4] = (-k[1] + k[3]) / (2 * k[0]);
    if (1 < k[4] && k[4] < INFINITY)
        res = fmin(k[4], res);
    k[4] = (-k[1] - k[3]) / (2 * k[0]);
    if (1 < k[4] && k[4] < INFINITY)
        res = fmin(k[4], res);
    return (res);
}

void    get_normal_sphere(t_vector3 *res, const t_vector3 *a, void *data)
{
    vector3_minus(res, a, &(((t_sphere *)data)->center));
    vector3_normalized(res);
}

uint    get_specular_sphere(void *data)
{
    return (((t_sphere *)data)->specular);

}
