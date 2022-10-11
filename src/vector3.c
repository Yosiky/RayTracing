#include "vector3.h"

void    set_coordinates(t_vector3 *ptr_point, const t_vector3 a)
{
    ptr_point->x = a.x;
    ptr_point->y = a.y;
    ptr_point->z = a.z;
}

void    vector3_minus(t_vector3 *a, const t_vector3 *b, const t_vector3 *c)
{
    a->x = b->x - c->x;
    a->y = b->y - c->y;
    a->z = b->z - c->z;
}

void    vector3_plus(t_vector3 *a, const t_vector3 *b, const t_vector3 *c)
{
    a->x = b->x + c->x;
    a->y = b->y + c->y;
    a->z = b->z + c->z;
}

double   vector3_dot(const t_vector3 *a, const t_vector3 *b)
{
    return (a->x * b->x + a->y * b->y + a->z * b->z);
}

void    vector3_cross(t_vector3 *dst, const t_vector3 *a, const t_vector3 *b)
{
    *dst = (t_vector3){a->z * b->y - a->y * b->z, a->x * b->z - a->z * b->x, a->y * b->x - a->x * b->y};
}


double   vector3_length(const t_vector3 *a)
{
    return (sqrt(vector3_dot(a, a)));
}

void    vector3_div(t_vector3 *dst, const t_vector3 *src, const double len)
{
    const double inv_len = 1 / len;

    dst->x = src->x * inv_len;
    dst->y = src->y * inv_len;
    dst->z = src->z * inv_len;
}

void    vector3_normalized(t_vector3 *src)
{
    vector3_div(src, src, vector3_length(src));
}

void    vector3_mul(t_vector3 *dst, const t_vector3 *src, const double value)
{
    dst->x = src->x * value;
    dst->y = src->y * value;
    dst->z = src->z * value;
}

void    vector3_mulv(t_vector3 *dst, const t_vector3 *src)
{
    dst->x *= src->x;
    dst->y *= src->y;
    dst->z *= src->z;
}
