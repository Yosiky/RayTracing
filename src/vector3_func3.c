#include "vector3.h"

static int	check_normal_value(double value)
{
	return (!(-1 - EPS < value && value < 1 + EPS));
}

void	normal_parse(t_vector3 *dst, char *str)
{
	char		**arg;
	uint32_t	count;

	arg = ft_split(str, ',');
	count = ee_split_count(arg);
	if (count != 3)
		ee_error(2, "ERROR: not valid count in vector");
	dst->x = ft_atof(arg[0]);
	dst->y = ft_atof(arg[1]);
	dst->z = ft_atof(arg[2]);
	if (check_normal_value(dst->x) || check_normal_value(dst->y)
		|| check_normal_value(dst->z))
		ee_error(10, "ERROR: not valid normal vector");
	ee_split_clear((char **)arg);
}

void	vector3_parse(t_vector3 *dst, char *str)
{
	char		**arg;
	uint32_t	count;

	arg = (char **)ft_split(str, ',');
	count = ee_split_count(arg);
	if (count != 3)
		ee_error(2, "ERROR: not valid count in vector");
	dst->x = ft_atof(arg[0]);
	dst->y = ft_atof(arg[1]);
	dst->z = ft_atof(arg[2]);
	ee_split_clear((char **)arg);
}

void	vector3_get_degree(int *x, int *y, t_vector3 *vec)
{
	*x = (int)round(atan2(vec->x,
				sqrt(vec->y * vec->y + vec->z * vec->z)) / PI * 180);
	*y = (int)round(atan2(vec->y,
				sqrt(vec->x * vec->x + vec->z * vec->z)) / PI * 180);
}

void	vector3_print(t_vector3 *vec)
{
	printf("{%lf, %lf, %lf}", vec->x, vec->y, vec->z);
}
