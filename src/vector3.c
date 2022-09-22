#include "vector3.h"

void    set_coordinates(t_vector3 *ptr_point, const float arr[3])
{
    ptr_point->x = arr[0];
    ptr_point->y = arr[1];
    ptr_point->z = arr[2];
}

void    vector3_minus(t_vector3 *a, const t_vector3 *b, const t_vector3 *c)
{
    a->x = b->x - c->x;
    a->y = b->y - c->y;
    a->z = b->z - c->z;
}

float   vector3_dot(const t_vector3 *a, const t_vector3 *b)
{
    return (a->x * b->x + a->y * b->y + a->z * b->z);
}

float   vector3_length(const t_vector3 *a)
{
    return (sqrt(vector3_dot(a, a)));
}

void    vector3_div(t_vector3 *dst, const t_vector3 *src, const float len)
{
    const float inv_len = 1 / len;

    dst->x = src->x * inv_len;
    dst->y = src->y * inv_len;
    dst->z = src->z * inv_len;
}

void    vector3_normalized(t_vector3 *src)
{
    vector3_div(src, src, vector3_length(src));
}
