#include "cylinder.h"
#include <stdio.h>

double   intersect_ray_cylinder(t_vector3 *restrict o, t_vector3 *restrict d,
        void *data)
{
    t_cylinder  *ptr = (t_cylinder *)data;
    t_vector3   oc;
    t_vector3   a;
    t_vector3   b;
    double      res;
    double      k[5];

    vector3_minus(&oc, o, &ptr->center);
    vector3_cross(&a, d, &ptr->normal);
    vector3_cross(&b, &oc, &ptr->normal);
    k[0] = vector3_dot(&a, &a);
    k[1] = vector3_dot(&a, &b) * 2.;
    k[2] = vector3_dot(&b, &b) - ptr->r * ptr->r;
    k[3] = k[1] * k[1] - 4 * k[0] * k[2];
    if (k[3] < EPS)
        return (INFINITY);
    res = INFINITY;
    k[3] = sqrt(k[3]);
    k[4] = (-k[1] + k[3]) / (2 * k[0]);
    if (EPS < k[4] && k[4] < INFINITY)
        res = fmin(k[4], res);
    k[4] = (-k[1] - k[3]) / (2 * k[0]);
    if (EPS < k[4] && k[4] < INFINITY)
        res = fmin(k[4], res);
    return (res);
}

void    get_normal_cylinder(t_vector3 *restrict res, t_vector3 *restrict a, void *data)
{
    t_cylinder  *ptr = (t_cylinder *)data;
    t_vector3   o;
    t_vector3   cp;
    double      pn_len;

    vector3_minus(&cp, a, &ptr->center);
    pn_len = vector3_dot(&ptr->normal, &cp);
    vector3_mul(&o, &ptr->normal, pn_len);
    vector3_plus(&o, &o, &ptr->center);
    vector3_minus(res, a, &o);
    vector3_normalized(res);
}

