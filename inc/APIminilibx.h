#ifndef APIMINILIBX_H
# define APIMINILIBX_H

# include "mlx.h"
# if __APPLE__
#  include <stdlib.h>
# else
#  include "malloc.h"
# endif

typedef unsigned int    uint;
typedef void*           t_mlx;

typedef struct s_image
{
    void    *img;
    uint    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    uint    x;
    uint    y;
} __attribute__((__packed__, __aligned__(8)))   t_image;

typedef struct s_window
{
    void        *win;
    int        x;
    int        y;
    const char  *name;
}  __attribute__((__packed__, __aligned__(8))) t_window;

t_window    *create_window(t_mlx mlx, int x, int y, char *str);
void        destroy_window(t_mlx mlx, t_window *win);
t_image     *create_image(t_mlx mlx, uint x, uint y);
void        destroy_image(t_mlx mlx, t_image *img);
void        ee_mlx_pixel_put(t_image *img, uint x, uint y, uint color);

#endif
