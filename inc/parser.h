#ifndef PARSER_H
# define PARSER_H

# include <stdint.h>
# include "libft.h"
# include "get_next_line.h"
# include "fcntl.h"
# include "objects.h"


enum PARSE_NUMBER
{
    PARSE_NONE_TYPE = -1,
    PARSE_AMBIENT,
    PARSE_POINT,
    PARSE_CAMERA,
    PARSE_SPHERE,
    PARSE_PLANE,
    PARSE_CYLINDER
};

typedef struct s_file
{
    char    **data;
    int     size;
    int     count;
}   t_file;

uint64_t    count_type_in_file(t_file *ptr);
t_file  *read_file(const char *name_file);
int     get_type_line(const char *str);
void    t_file_clean(t_file *ptr);

#endif
