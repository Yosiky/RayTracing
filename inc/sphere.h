#ifndef SPHERE_H
# define SPHERE_H

# include "vector3.h"
# include "ee_list.h"
# include "math.h"
# include "limits.h"

# define EPS 0.0001

typedef unsigned int    uint;

typedef struct s_sphere
{
    t_vector3   center;
    double       r;
    uint        color;
    uint        specular;
}   t_sphere;

uint    get_color_sphere(void *data);
uint    get_specular_sphere(void *data);
double   intersect_ray_sphere(t_vector3 *o, t_vector3 *d, void *data);
void    get_normal_sphere(t_vector3 *res, const t_vector3 *a, void *lst);


#endif
