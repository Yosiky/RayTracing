#include "miniRT.h"
#include "unistd.h"

double get_cos(int ind)
{
	static const double pi = PI / 180;
	static double   *arr = NULL;
	int             i;

	if (ind < 0)
		ind = 360 - ind;
	if (arr == NULL)
	{
		arr = (double *)malloc(sizeof(double) * 360);
		i = -1;
		while (++i < 360)
			arr[i] = cos(pi * i);
	}
	return (arr[ind]);
}

double get_sin(int ind)
{
	static const double pi = PI / 180;
	static double   *arr = NULL;
	int             i;

	if (ind < 0)
		ind = 360 - ind;
	if (arr == NULL)
	{
		arr = (double *)malloc(sizeof(double) * 360);
		i = -1;
		while (++i < 360)
			arr[i] = sin(pi * i);
	}
	return (arr[ind]);
}

void    rotate_x(t_vector3 *d, int a)
{
	const t_vector3 copy = *d;
	const double cos1 = cos(a * PI / 180);//get_cos(a);
	const double sin1 = sin(a * PI / 180);//get_sin(a);

	d->x = 1 * d->x;
	d->y = d->y * cos1 - d->z * sin1;
	d->z = copy.y * sin1 + copy.z * cos1;
}

void    rotate_y(t_vector3 *d, int a)
{
	const t_vector3 copy = *d;
	const double cos1 = cos(a * PI / 180);
	const double sin1 = sin(a * PI / 180);;

	d->x = copy.x * cos1 + copy.z * sin1;
	d->y = copy.y;
	d->z = copy.z * cos1 - copy.x * sin1;
}

typedef void    (*t_rotate)(t_vector3 *, int a);

void    rotate(t_vector3 *d, int flag)
{
	static const t_rotate   rot[] = {rotate_x, rotate_y};
	static int rotx = 0;
	static int roty = 0;

	if (flag)
	{
		rotx = *(get_rotate_x(NULL));
		roty = *(get_rotate_y(NULL));
	}
	if (d != NULL)
	{
		rot[0](d, rotx);
		rot[1](d, roty);
	}
}

int event_move(int key, __attribute__((__unused__))void *arg)
{
	write(1, "1", 1);
	t_vector3    o = {0, 0, 0};

	if (key == KEY_R)
		*(get_rotate_x(NULL)) -= 1;
	if (key == KEY_F)
		*(get_rotate_x(NULL)) += 1;
	if (key == KEY_Q)
		*(get_rotate_y(NULL)) -= 1;
	if (key == KEY_E)
		*(get_rotate_y(NULL)) += 1;
	if (key == KEY_W)
		o.z += 0.1;
	if (key == KEY_S)
		o.z -= 0.1;
	if (key == KEY_D)
		o.x += 0.1;
	if (key == KEY_A)
		o.x -= 0.1;
	if (key == KEY_ESCAPE)
		exit(0);
	rotate(&o, 1);
	vector3_plus(get_viewer(NULL), &o, get_viewer(NULL));
	draw_on_img(get_image(NULL), get_object(NULL));
	mlx_put_image_to_window(get_mlx(NULL), get_window(NULL)->win, get_image(NULL)->img, 0, 0);
	write(1, "0", 1);
	return (0);
}
