#include "APIminilibx.h"

t_window    *create_window(t_mlx mlx, uint x, uint y, const char *str)
{
    void        *window;
    t_window    *win;

    window = (void *)mlx_new_window(mlx, x, y, (char *)str);
    if (window == NULL)
        return (NULL);
    win = (t_window *)malloc(sizeof(t_window));
    if (win == NULL)
    {
        free(window);
        return (NULL);
    }
    win->x = x;
    win->y = y;
    win->win = window;
    win->name = str;
    return (win);
}

void        destroy_window(t_mlx mlx, t_window *win)
{
    mlx_destroy_window(mlx, win->win);
    free(win);
}

t_image     *create_image(t_mlx mlx, uint x, uint y)
{
    void        *image;                               
    t_image     *img;
                                                     
    image = (void *)mlx_new_image(mlx, x, y);
    if (image == NULL)
        return (NULL);
    img = (t_image *)malloc(sizeof(t_image));
    if (img == NULL)
    {
        free(image);
        return (NULL);
    }
    img->img = image;
    img->x = x;
    img->y = y;
    img->addr = (uint *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    img->line_length /= img->bits_per_pixel / 8;
    return (img);
}

void        destroy_image(t_mlx mlx, t_image *img)
{
    mlx_destroy_image(mlx, img->img);
    free(img);
}

void    ee_mlx_pixel_put(t_image *img, uint x, uint y, uint color)
{
    img->addr[y * img->line_length + x] = color;
}
