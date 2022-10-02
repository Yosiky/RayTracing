#ifndef OBJECTS_H
# define OBJECTS_H

# include <sys/types.h>
# include "sphere.h"

typedef double  (*t_intersec_ray)(t_vector3 *, t_vector3 *, void *);
typedef void    (*t_get_normal)(t_vector3 *, const t_vector3 *, void *);


typedef struct s_object
{
    uint        type;
    uint        color;
    uint        specular;
    double      reflective;
    union
    {
        t_sphere    *sphere;
    }   obj;
} __attribute__((__packed__, __aligned__(8)))   t_object;

#endif
