#ifndef VECTOR3_H
# define VECTOR3_H

typedef struct s_vector3
{
    float   x;
    float   y;
    float   z;
}   t_vector3;

void    set_coordinates(t_vector3 *ptr_point, const float const arr[3]);

#endif
