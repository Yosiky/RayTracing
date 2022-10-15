#include "libft.h"

void    *ee_malloc(size_t count)
{
    void    *res;

    res = malloc(count);
    if (res == NULL)
        ee_error(1, "can't alloc memory");
    return (res);
}
