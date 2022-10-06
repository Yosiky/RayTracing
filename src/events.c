#include "miniRT.h"
#include "unistd.h"

#define KEY_W 13
#define PI 3.14

void    rotate_x(t_vector3 *d, int a)
{
    const t_vector3 copy = *d;
    const double cos1 = cos(a * PI / 180);
    const double sin1 = sin(a * PI / 180);

    d->x = 1 * d->x;
    d->y = d->y * cos1 - d->z * sin1;
    d->z = copy.y * sin1 + copy.z * cos1;
}

typedef void    (*t_rotate)(t_vector3 *, int a);

void    rotate(t_vector3 *d, int t, int x, int y)
{
    static int type = -1;
    static const t_rotate   rot[] = {NULL, rotate_x};
    static int rotx = 0;
    static int roty = 0;
    
    if (t == 0)
    {
        if (type == 1)
            rot[type](d, rotx);
    }
    else if (d == NULL)
    {
        type = t;
        rotx = x;
        roty = y;
    }
}

int event_move(int key, __attribute__((__unused__))void *arg)
{
    static int rotx = 0;
    static int roty = 0;
    static int type = 0;

    write(1, "1", 1);
    if (key == KEY_W)
    {
        rotx += 1;
        type = 1;
    }
    rotate(NULL, type, rotx, roty);
    draw_on_img(get_image(NULL), get_object(NULL));
    mlx_put_image_to_window(get_mlx(NULL), get_window(NULL)->win, get_image(NULL)->img, 0, 0);
    write(1, "0", 1);
    return (0);
}
