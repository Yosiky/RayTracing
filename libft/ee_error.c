#include "libft.h"

void    ee_error(int code, const char *str)
{
    write(2, str, ft_strlen(str));
    exit(code);
}
