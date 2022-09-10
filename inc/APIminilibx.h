#ifndef APIMINILIBX_H
# define APIMINILIBX_H

# include "mlx.h"
# if __APPLE__
#  include "stdlib.h"
# else
#  include "malloc.h"
# endif

typedef unsigned int    uint;
typedef void*           t_mlx;

typedef struct s_image
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    uint    x;
    uint    y;
}   t_image;

typedef struct s_window
{
    void        *win;
    uint        x;
    uint        y;
    const char  *name;
}   t_window;

t_window    *create_window(t_mlx mlx, uint x, uint y, const char *str);
void        destroy_window(t_mlx mlx, t_window *win);
t_image     *create_image(t_mlx mlx, uint x, uint y);
void        *destroy_image(t_mlx mlx, t_image *img);
void        ee_mlx_pixel_put(t_image *img, uint x, uint y, int color);

#endif
