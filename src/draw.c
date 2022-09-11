#include "miniRT.h"

uint    trace_ray(uint x, uint y, t_eelist *lst)
{



}

void    draw_on_img(t_image *img, t_eelist *lst)
{
    uint        x;
    uint        y;
    uint        color;
    t_vector3   O;
    t_vector3   d;

    set_coordinates(&O, (float []){0, 0, 0});
    while (x < img->x)
    {
        while (y < img->y)
        {
            set_coordinates(&d, (float []){ x / WINDOW_X * SCREEN_IMG_X, y / WINDOW_Y * SCREEN_IMG_Y, 1});
            color = trace_ray(x, y, lst);
            ee_mlx_pixel_put(img, x, y, color);
        }
    }
}
