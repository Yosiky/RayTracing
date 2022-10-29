#include "miniRT.h"
#include <stdio.h>

int ee_exit(void)
{
    exit(0);
}

void    init_hook(t_window *ptr_window)
{
    mlx_key_hook(ptr_window->win, event_move, NULL);
    mlx_hook(ptr_window->win, 17, 0, ee_exit, NULL);
}

int main(int argc, char **argv)
{
    t_file  *ptr_file;

    if (argc == 2)
    {
        ptr_file = read_file(argv[1]);
        parse_data(ptr_file);
        t_file_clean(ptr_file);
        t_object *obj = get_object(NULL);
        t_light *light = get_light(NULL);

        for (int i = 0; obj[i].type != OBJ_NONE; ++i)
        {
            print_obj(&obj[i]);
        }

        t_mlx *ptr_mlx = mlx_init();
        t_window    *ptr_window;
        t_image     *ptr_image;
        if (ptr_mlx == NULL)
            ee_error(1, "Can't init mlx");
        ptr_window = create_window(ptr_mlx, WINDOW_X, WINDOW_Y, WINDOW_NAME);
        ptr_image = create_image(ptr_mlx, IMG_X, IMG_Y);
        init_hook(ptr_window);
        get_image(ptr_image);
        get_window(ptr_window);
        get_mlx(ptr_mlx);
        draw_on_img(ptr_image, get_object(NULL));
        mlx_put_image_to_window(ptr_mlx, ptr_window->win, ptr_image->img, 0, 0);
        mlx_loop(ptr_mlx);
    }
    else
        ee_error(3, "Error: not valid count arg");
    return (0);
}
