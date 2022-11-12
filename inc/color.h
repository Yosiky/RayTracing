#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>
# include <math.h>

# define MASK_BYTE  0x000000ff


typedef unsigned char   t_uchar;

typedef struct s_color
{
    double  arr[4];
}   t_color;

typedef union u_color
{
    uint32_t    color;
    

}   t_ucolor;

t_color *color_create(t_color *res, uint32_t a, double intensity);
t_color *color_add(t_color *res, t_color *a, t_color *b);
t_color *color_mul(t_color *res, t_color *a, t_color *b);
uint32_t    color_double_int(t_color *color);
t_color color_init(double arr[4]);

#endif
