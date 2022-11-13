#include "vector3.h"

double	vector3_length(const t_vector3 *a)
{
	return (sqrt(vector3_dot(a, a)));
}

void	vector3_div(t_vector3 *dst, const t_vector3 *src, const double len)
{
	const double	inv_len = 1 / len;

	dst->x = src->x * inv_len;
	dst->y = src->y * inv_len;
	dst->z = src->z * inv_len;
}

void	vector3_normalized(t_vector3 *src)
{
	vector3_div(src, src, vector3_length(src));
}

void	vector3_mul(t_vector3 *dst, const t_vector3 *src, const double value)
{
	dst->x = src->x * value;
	dst->y = src->y * value;
	dst->z = src->z * value;
}

void	vector3_mulv(t_vector3 *dst, const t_vector3 *src)
{
	dst->x *= src->x;
	dst->y *= src->y;
	dst->z *= src->z;
}
