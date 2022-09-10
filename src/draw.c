#include "miniRT.h"


void    draw(t_window *win, t_image *img, void)
{
    uint    x;
    uint    y;
    uint    color;

    while (x < img->x)
        while (y < img->y)
        {
            put_pixel(x, y, color);
        }
}
