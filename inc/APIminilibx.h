#ifndef APIMINILIBX_H
# define APIMINILIBX_H

# include "minilibx.h"
# if __APPLE__
#  define "stdlib.h"
# else
#  define "malloc.h"
# endif

typedef unsigned int    int;
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
    void        *window;
    uint        x;
    uint        y;
    const char  *str;
}   t_window;

t_window    *create_window(t_mlx *mlx, uint x, uint y);
void        destroy_window(t_window *win);
t_image     *create_image(t_mlx *mlx, uint x, uint y);
void        *destroy_image(t_image *img);
void        mlx_pixel_put(t_image *img, uint x, uint y, uint color)

#endif
