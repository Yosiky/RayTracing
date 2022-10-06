#include "miniRT.h"
#include "unistd.h"

#define KEY_W 13
#define KEY_S 1
#define KEY_D 2
#define KEY_A 0
#define KEY_R 15
#define KEY_F 3
#define KEY_Q 12
#define KEY_E 14

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

void    rotate_y(t_vector3 *d, int a)
{
    const t_vector3 copy = *d;
    const double cos1 = cos(a * PI / 180);
    const double sin1 = sin(a * PI / 180);

    d->x = copy.x * cos1 + copy.z * sin1;
    d->y = copy.y;
    d->z = copy.z * cos1 - copy.x * sin1;
}

typedef void    (*t_rotate)(t_vector3 *, int a);

void    rotate(t_vector3 *d, int x, int y)
{
    static const t_rotate   rot[] = {rotate_x, rotate_y};
    static int rotx = 0;
    static int roty = 0;

    if (d == NULL)
    {
        rotx = x;
        roty = y;
    }
    else 
    {
        rot[0](d, rotx);
        rot[1](d, roty);
    }
}

int event_move(int key, __attribute__((__unused__))void *arg)
{
    t_vector3    o = {0, 0, 0};
    static int rotx = 0;
    static int roty = 0;

    write(1, "1", 1);
    if (key == KEY_R)
        rotx -= 1;
    if (key == KEY_F)
        rotx += 1;
    if (key == KEY_Q)
        roty -= 1;
    if (key == KEY_E)
        roty += 1;
    if (key == KEY_W)
        o.z += 0.1;
    if (key == KEY_S)
        o.z -= 0.1;
    if (key == KEY_D)
        o.x += 0.1;
    if (key == KEY_A)
        o.x -= 0.1;
    rotate(NULL, rotx, roty);
    rotate(&o, 0, 0);
    vector3_plus(&o, &o, get_viewer(NULL));
    get_viewer(&o);
    draw_on_img(get_image(NULL), get_object(NULL));
    mlx_put_image_to_window(get_mlx(NULL), get_window(NULL)->win, get_image(NULL)->img, 0, 0);
    write(1, "0", 1);
    return (0);
}
