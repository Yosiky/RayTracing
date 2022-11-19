#include "parser.h"

int	get_type_line(const char *str)
{
	if (ft_strncmp(str, "A", 1) == 0)
		return (PARSE_AMBIENT);
	if (ft_strncmp(str, "L", 1) == 0)
		return (PARSE_POINT);
	if (ft_strncmp(str, "C", 1) == 0)
		return (PARSE_CAMERA);
	if (ft_strncmp(str, "sp", 2) == 0)
		return (PARSE_SPHERE);
	if (ft_strncmp(str, "pl", 2) == 0)
		return (PARSE_PLANE);
	if (ft_strncmp(str, "cy", 2) == 0)
		return (PARSE_CYLINDER);
	return (PARSE_NONE_TYPE);
}

static void	*ee_realloc(void *src, size_t size, size_t type)
{
	void	*res;

	res = ee_malloc(type * (size + SIZE_ALLOC_MEM));
	ft_memcpy(res, src, type * size);
	free(src);
	return (res);
}

t_file	*read_file(const char *name_file)
{
	int		fd;
	char	*line;
	t_file	*file;

	file = (t_file *)ee_malloc(sizeof(t_file));
	file->size = SIZE_ALLOC_MEM;
	file->count = 0;
	file->data = (char **)ee_malloc(sizeof(char **) * file->size);
	fd = open(name_file, O_RDONLY);
	if (fd == -1)
		ee_error(2, "ERROR: can't open file");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (file);
		if (!ft_strlen(line) || !ft_strncmp(line, "\n", 1))
			continue ;
		file->data[file->count++] = line;
		if (file->count == file->size)
		{
			file->data = (char **)ee_realloc((void *)file->data,
					file->size, sizeof(char **));
			file->size += SIZE_ALLOC_MEM;
		}
	}
	return ()
}

void	t_file_clean(t_file *ptr)
{
	while (ptr->count > 0)
		free(ptr->data[--ptr->count]);
	free(ptr->data);
	free(ptr);
}

uint64_t	count_type_in_file(t_file *ptr)
{
	uint	count_obj;
	uint	count_light;
	uint	i;
	int		type;

	count_obj = 0;
	count_light = 0;
	i = 0;
	while (i < ptr->count)
	{
		type = get_type_line(ptr->data[i++]);
		if (type == PARSE_NONE_TYPE)
			ee_error(2, "ERROR: not valid file");
		if (type == PARSE_AMBIENT || type == PARSE_POINT)
			count_light += 1;
		else if (type > PARSE_CAMERA)
			count_obj += 1;
	}
	return (((uint64_t)count_obj << 32) + count_light);
}

