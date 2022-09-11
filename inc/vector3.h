#ifndef VECTOR3_H
# define VECTOR3_H

typedef struct s_vector3
{
    float   x;
    float   y;
    float   z;
}   t_vector3;

void    set_coordinates(t_vector3 *ptr_point, const float arr[3]);
void    vector3_minus(t_vector3 *a, const t_vector3 *b, const t_vector3 *c);
float   vector3_dot(const t_vector3 *a, const t_vector3 *b);

#endif
