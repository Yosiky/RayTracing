#include "plane.h"

double	intersect_ray_plane(t_vector3 *restrict o, t_vector3 *restrict d,
		void *data)
{
	t_plane		*plane;
	t_vector3	v;
	double		res;
	double		dot;
	double		lenght;

	plane = (t_plane *)data;
	dot = vector3_dot(&plane->normal, d);
	vector3_minus(&v, &plane->point, o);
	lenght = vector3_dot(&plane->normal, &v);
	res = INFINITY;
	res = fmin(lenght / dot, res);
	if (EPS < res)
		return (res);
	return (INFINITY);
}

void	get_normal_plane(t_vector3 *restrict res, UNUSED t_vector3 *restrict a,
		void *data)
{
	t_plane	*plane;

	plane = (t_plane *)data;
	*res = plane->normal;
}
