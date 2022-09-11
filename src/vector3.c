#include "vector3.h"

void    set_coordinates(t_vector3 *ptr_point, const float const arr[3])
{
    ptr_point->x = arr[0];
    ptr_point->y = arr[1];
    ptr_point->z = arr[2];
}
