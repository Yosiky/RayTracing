#ifndef SPHERE_H
# define SPHERE_H

# include "vector3.h"
# include <sys/types.h>
# include "ee_list.h"
# include "math.h"
# include "limits.h"
# include "constants.h"


typedef struct s_sphere
{
    double      r;
    t_vector3   center;
} __attribute__((__packed__, __aligned__(8)))   t_sphere;

double   intersect_ray_sphere(t_vector3 *restrict o, t_vector3 *restrict d,
        void *data);
void    get_normal_sphere(t_vector3 *restrict res, t_vector3 *restrict a,
        void *data);

#endif
