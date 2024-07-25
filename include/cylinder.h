#ifndef cylinder_H
# define cylinder_H

# include "vector3.h"
# include "constants.h"

typedef struct s_cylinder
{
    double  r;
    double  hight;
    t_vector3   center;
    t_vector3   normal;
}  __attribute__((__packed__, __aligned__(8))) t_cylinder;

double   intersect_ray_cylinder(t_vector3 *restrict o, t_vector3 *restrict d,
        void *data);
void    get_normal_cylinder(t_vector3 *restrict res, t_vector3 *restrict a, void *data);

#endif
