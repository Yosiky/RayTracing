#ifndef SPHERE_H
# define SPHERE_H

# include "vector3.h"
# include "ee_list.h"
# include "math.h"
# include "limits.h"

typedef unsigned int    uint;

typedef struct s_sphere
{
    t_vector3   center;
    float       r;
    uint        color;
}   t_sphere;

uint    get_color_sphere(t_eelist *lst);
t_vector3   intersect_ray_sphere(t_vector3 *o, t_vector3 *d, t_eelist *lst);
void    get_normal_sphere(t_vector3 *res, const t_vector3 *a, t_eelist *lst);

#endif
