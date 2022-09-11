#ifndef SPHERE_H
# define SPHERE_H

# include "vector3.h"

typedef unsigned int    uint;

typedef struct s_sphere
{
    t_vector3   center;
    float       r;
    uint        color;
}   t_sphere;

#endif
