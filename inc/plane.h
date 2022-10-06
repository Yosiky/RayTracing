#ifndef PLANE_H
# define PLANE_H

# include "vector3.h"
# include <sys/types.h>
# include "ee_list.h"
# include "math.h"
# include "limits.h"

union   fast_vector3
{
    double      arr[3];
    t_vector3   point;
};

typedef struct s_plane
{
    union fast_vector3    points[3];
} __attribute__((__packed__, __aligned__(8)))   t_plane;

double   intersect_ray_plane(t_vector3 *restrict o, t_vector3 *restrict d,
        void *data);
void    get_normal_plane(t_vector3 *restrict res, const t_vector3 *restrict a,
        void *data);

#endif
