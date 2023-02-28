/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:37:06 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/28 22:46:54 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	create_light(const char *str, void *dst)
{
	t_light *const	light = (t_light * const)dst;
	char **const	arg = (char **)ft_split(str, ' ');
	const uint		count = (const uint)ee_split_count(arg);
	uint			i;

	if ((arg[0][0] == 'A' && !(count == 2 || count == 3)) ||
		(arg[0][0] == 'L' && !(count == 3 || count == 4)))
		ee_error(2, "ERROR: invalid data in file\n");
	i = 0;
	light->type = get_type_line(arg[i++]) - PARSE_AMBIENT;
	if (light->type == LIGHT_POINT)
		vector3_parse(&light->position, arg[i++]);
	light->intensity = ft_atof(arg[i++]);
	if (light->intensity < EPS || light->intensity > 1 - EPS)
		ee_error(8, "ERROR: invalid intensity in file\n");
	if ((light->type == LIGHT_AMBIENT && count == 3)
		|| (light->type == LIGHT_POINT && count == 4))
		light->color = ee_color_parse(arg[i]);
	ee_split_clear((char **)arg);
}

void	create_camera(const char *str, void *dst)
{
	t_camera *const	data = (t_camera * const)dst;
	char **const	arg = (char **)ft_split(str, ' ');
	const uint		count = (const uint)ee_split_count(arg);

	if (count != 4)
		ee_error(2, "ERROR: invalid data in file\n");
	vector3_parse(&data->coordinate, arg[1]);
	normal_parse(&data->normal, arg[2]);
	vector3_get_degree(&data->rotate_x, &data->rotate_y, &data->normal);
	data->view = (uint)ft_atoi(arg[3]);
	ee_split_clear((char **)arg);
}

void	create_sphere(const char *str, void *dst)
{
	t_object *const	data = (t_object * const)dst;
	char **const	arg = (char **)ft_split(str, ' ');
	const uint		count = (const uint)ee_split_count(arg);

	if (count != 4)
		ee_error(2, "ERROR: invalid data in file\n");
	data->u_obj.sphere = (t_sphere *)ee_malloc(sizeof(t_sphere));
	vector3_parse(&data->u_obj.sphere->center, arg[1]);
	data->u_obj.sphere->r = ft_atof(arg[2]) / 2;
	data->type = OBJ_SPHERE;
	data->specular = 100;
	data->reflective = 0;
	data->color = ee_color_parse(arg[3]);
	ee_split_clear((char **)arg);
}

void	create_plane(const char *str, void *dst)
{
	t_object *const	data = (t_object * const)dst;
	char **const	arg = (char **)ft_split(str, ' ');
	const uint		count = (const uint)ee_split_count(arg);

	if (count != 4)
		ee_error(2, "ERROR: invalid data in file\n");
	data->u_obj.plane = (t_plane *)ee_malloc(sizeof(t_plane));
	vector3_parse(&data->u_obj.plane->point, arg[1]);
	normal_parse(&data->u_obj.plane->normal, arg[2]);
	data->type = OBJ_PLANE;
	data->specular = 100;
	data->reflective = 0;
	data->color = ee_color_parse(arg[3]);
	ee_split_clear((char **)arg);
}

void	create_cylinder(const char *str, void *dst)
{
	t_object *const	data = (t_object * const)dst;
	char **const	arg = (char **)ft_split(str, ' ');
	const uint		count = (const uint)ee_split_count(arg);

	if (count != 6)
		ee_error(2, "ERROR: invalid data in file\n");
	data->u_obj.cylinder = (t_cylinder *)ee_malloc(sizeof(t_cylinder));
	vector3_parse(&data->u_obj.cylinder->center, arg[1]);
	normal_parse(&data->u_obj.cylinder->normal, arg[2]);
	data->u_obj.cylinder->r = ft_atof(arg[3]) / 2;
	data->u_obj.cylinder->hight = ft_atof(arg[4]);
	if (data->u_obj.cylinder->hight < EPS)
	{
		vector3_mul(&data->u_obj.cylinder->normal,
			&data->u_obj.cylinder->normal, -1);
		vector3_normalized(&data->u_obj.cylinder->normal);
		data->u_obj.cylinder->hight = fabs(data->u_obj.cylinder->hight);
	}
	data->type = OBJ_CYLINDER;
	data->specular = 100;
	data->reflective = 0;
	data->color = ee_color_parse(arg[5]);
	ee_split_clear((char **)arg);
}
