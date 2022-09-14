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

float   vector3_dot(const t_vector3 *restrict a, const t_vector3 *restrict b)
{
    return (a->x * b->x + a->y * b->y + a->z * b->z);
}

float   vector3_length(const t_vector3 *a)
{
    return (sqrt(vector3_dot(a, a)));
}

void    vector3_div(t_vector3 *dst, const t_vector3 *src, const float len)
{
    dst->x = src->x / len;
    dst->y = src->y / len;
    dst->z = src->z / len;
}
