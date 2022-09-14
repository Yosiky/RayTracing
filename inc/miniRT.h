#ifndef MINIRT_H
# define MINIRT_H

# include "APIminilibx.h"
# include "vector3.h"
# include "ee_list.h"
# include "light.h"
# include "sphere.h"
# include <limits.h>
# include <math.h>
# include <unistd.h>

#include <stdio.h>

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
typedef void        (*t_get_normal)(t_vector3 *res, const t_vector3 *a, t_eelist *lst);

typedef struct s_work_with_figure
{
    t_intersect_ray intersect_ray;
    t_get_color     get_color;
    t_get_normal    get_normal;
}   t_work_figure;

void    ee_error(int code, const char *str);
void    draw_on_img(t_image *img, t_eelist *lst, t_work_figure *funcs);

#endif
