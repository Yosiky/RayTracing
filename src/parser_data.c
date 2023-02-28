/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <yosiky@list.ru>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:19:17 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/27 22:19:20 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

uint	ee_color_parse(char *str)
{
	char		**arg;
	uint		dst;
	int			i;
	uint		value;
	const uint	ind[] = {16, 8, 0};

	dst = 0;
	arg = ft_split(str, ',');
	value = ee_split_count(arg);
	if (value != 3)
		ee_error(11, "ERROR: not valid count color\n");
	i = 0;
	while (i < 3)
	{
		value = (uint)ft_atoi(arg[i]);
		if (value > 255)
			ee_error(9, "ERROR: don't valid color\n");
		dst += value << ind[i];
		++i;
	}
	ee_split_clear(arg);
	return (dst);
}

typedef void	(*t_func_creator)(const char *str, void *dst);

static void	init_arr_obj(t_camera **camera, t_object **obj,
	t_light **light, uint64_t *count)
{
	*obj = (t_object *)ee_malloc(sizeof(t_object) * (count[1] + 1));
	*light = (t_light *)ee_malloc(sizeof(t_light) * (count[2] + 1));
	*camera = (t_camera *)ee_malloc(sizeof(t_camera));
	(*obj)[count[1]].type = OBJ_NONE;
	(*light)[count[2]].type = LIGHT_NONE;
	get_camera(*camera);
	get_object(*obj);
	get_light(*light);
}

static void	init_count_arr(t_file *ptr, uint64_t *count)
{
	count[0] = count_type_in_file(ptr);
	count[1] = count[0] >> 32;
	count[2] = count[0] & 0xffffffff;
	count[3] = (uint64_t)-1;
	count[4] = 0;
	count[5] = 0;
}

void	parse_data(t_file *ptr)
{
	static t_func_creator	func[] = {create_light, create_light,
		create_camera, create_sphere, create_plane, create_cylinder};
	uint64_t				count[6];
	t_camera				*camera;
	t_object				*obj;
	t_light					*light;

	init_count_arr(ptr, count);
	init_arr_obj(&camera, &obj, &light, count);
	while (++count[3] < ptr->count)
	{
		count[5] = (uint64_t)get_type_line(ptr->data[count[3]]);
		if ((count[4] & 0x1 && count[5] == PARSE_AMBIENT)
			|| (count[4] & 0x2 && count[5] == PARSE_POINT)
			|| (count[4] & 0x4 && count[5] == PARSE_CAMERA))
			ee_error(7, "ERROR: don't valid file\n");
		count[4] |= 1 << count[5];
		if (count[5] == PARSE_AMBIENT || count[5] == PARSE_POINT)
			func[count[5]](ptr->data[count[3]], (void *)&light[--count[2]]);
		else if (count[5] == PARSE_CAMERA)
			func[count[5]](ptr->data[count[3]], (void *)camera);
		else if (count[5] > PARSE_CAMERA)
			func[count[5]](ptr->data[count[3]], (void *)&obj[--count[1]]);
	}
}
