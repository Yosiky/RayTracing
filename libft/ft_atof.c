#include "libft.h"

static double   get_double_part(const char *str)
{
    double  dst;
    uint    count;
    
    if (*str != '.')
        return (0);
    ++str;
    dst = 0;
    count = 0;
    while (ft_isdigit(str[count]))
        ++count;
    while (count-- > 0)
        dst = (dst + (str[count] - '0')) * 0.1;
    return (dst);
}

double ft_atof(const char *str)
{
    double  dst;

    dst = (double)ft_atoi(str);
    while (ft_isdigit(*str))
        ++str;
    dst += get_double_part(str);
    return (dst);
}
