#ifndef MINIRT_H
# define MINIRT_H

# include "APIminilibx.h"
# include "vector3.h"
# include "ee_list.h"
# include "sphere.h"
# include <limits.h>
# include <math.h>

# define WINDOW_NAME "miniRT"
# define WINDOW_X 1000
# define WINDOW_Y 1000
# define IMG_X 1000
# define IMG_Y 1000
# define SCREEN_IMG_X 1900
# define SCREEN_IMG_Y 1024

# define COLOR_BACKGROUND   0X00000000
# define EPS                0.00001

typedef t_vector3   (*t_intersect_ray)(t_vector3 *o, t_vector3 *d, t_eelist *lst);
typedef uint        (*t_get_color)(t_eelist *lst);

typedef struct s_work_with_figure
{
    t_intersect_ray intersect_ray;
    t_get_color     get_color;
}   t_work_figure;

void    ee_error(int code, const char *str);

uint        get_color_sphere(t_eelist *lst);
t_vector3   intersect_ray_sphere(t_vector3 *o, t_vector3 *d, t_eelist *lst);




#endif
