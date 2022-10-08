#ifndef OBJECTS_H
# define OBJECTS_H

# include <sys/types.h>
# include "sphere.h"
# include "plane.h"

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
        void        *start;
        t_sphere    *sphere;
        t_plane     *plane;
        
    }   obj;
} __attribute__((__packed__, __aligned__(8)))   t_object;

double  intersect_ray(t_vector3 *o, t_vector3 *d, t_object *obj);
void    get_normal(t_vector3 *dst, t_vector3 *one, t_object *obj);

#endif
