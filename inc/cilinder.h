#ifndef CILINDER_H
# define CILINDER_H

# include "vector3.h"
# include "constants.h"

typedef struct s_cilinder
{
    double  r;
    double  hight;
    t_vector3   center;
    t_vector3   normal;
}  __attribute__((__packed__, __aligned__(8))) t_cilinder;

double   intersect_ray_cilinder(t_vector3 *restrict o, t_vector3 *restrict d,
        void *data);
void    get_normal_cilinder(t_vector3 *restrict res, t_vector3 *restrict a, void *data);

#endif
