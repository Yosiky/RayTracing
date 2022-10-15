#ifndef MINIRT_H
# define MINIRT_H

# include "constants.h"
# include "APIminilibx.h"
# include "vector3.h"
# include "ee_list.h"
# include "light.h"
# include "parser.h"
# include "libft.h"
# include "constants.h"

# include "objects.h"
# include <limits.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>


# define WINDOW_NAME "miniRT"
# define WINDOW_X 1000
# define WINDOW_Y 1000
# define IMG_X 1000
# define IMG_Y 1000
# define SCREEN_IMG_X WINDOW_X
# define SCREEN_IMG_Y WINDOW_Y

# define RECURSIVE_DEPTH 5
# define COLOR_BACKGROUND   0X00000000

void    draw_on_img(t_image *img, t_object *objects);
int event_move(int key, void *arg);
void    rotate(t_vector3 *d, int x, int y, int flag);
t_object    *get_object(t_object *ptr);
t_image    *get_image(t_image *ptr);
t_window    *get_window(t_window *ptr);
t_mlx    *get_mlx(t_mlx *ptr);
t_vector3    *get_viewer(t_vector3 *ptr);

#endif
