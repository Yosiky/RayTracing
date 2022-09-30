#ifndef VECTOR3_H
# define VECTOR3_H

# include "math.h"

typedef struct s_vector3
{
    double   x;
    double   y;
    double   z;
}   t_vector3;

void    set_coordinates(t_vector3 *ptr_point, const t_vector3 a);
void    vector3_minus(t_vector3 *a, const t_vector3 *b, const t_vector3 *c);
double   vector3_dot(const t_vector3 *a, const t_vector3 *b);
double   vector3_length(const t_vector3 *a);
void    vector3_div(t_vector3 *dst, const t_vector3 *src, const double len);
void    vector3_normalized(t_vector3 *src);
void    vector3_mul(t_vector3 *dst, const t_vector3 *src, const double value);

#endif
