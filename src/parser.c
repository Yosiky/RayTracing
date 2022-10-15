#include "parser.h"

static int  get_type_line(const char *str)
{
    const int   len = ft_strlen(str);
    
    if (len == 0 || len > 2)
        return (-1);
    if (ft_strncmp(str, "A", 1) == 0)
        return (0);
    if (ft_strncmp(str, "L", 1) == 0)
        return (1);
    if (ft_strncmp(str, "C", 1) == 0)
        return (2);
    if (ft_strncmp(str, "cp", 2) == 0)
        return (3);
    if (ft_strncmp(str, "pl", 2) == 0)
        return (4);
    if (ft_strncmp(str, "cy", 2) == 0)
        return (5);
    return (-1);
}

static void *get_data(const char **arr, int type)
{
    if (type == -1)
        return (NULL);
    return (NULL);
}

static void *parse_line(const char *str)
{
    const char  **value = (const char **)ft_split(str, ' ');

    return (get_data(value + 1, get_type_line(*value)));
}

static void *ee_realloc(void *src, size_t size, size_t type)
{
    void    *res;

    res = ee_malloc(type * (size + SIZE_ALLOC_MEM));
    ft_memcpy(res, src, type * size);
    free(src);
    return (res);
}

t_file  *parser(const char *name_file)
{
    int     fd;
    int     indx;
    char    *line;
    t_file  *file;

    file = (t_file *)ee_malloc(sizeof(t_file));
    file->size = SIZE_ALLOC_MEM;
    file->data = (char **)ee_malloc(sizeof(char **) * file->size);
    fd = open(name_file, O_RDONLY);
    if (fd == -1)
        ee_error(2, "can't open file");
    indx = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            return (file);
        if (!ft_strlen(line))
            continue ;
        if (indx == file->size)
        {
            file->data = (char **)ee_realloc((void *)file->data, file->size, sizeof(char **));
            file->size += SIZE_ALLOC_MEM;
        }
    }
}
