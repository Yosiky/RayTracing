#include "miniRT.h"

#include <string.h>

void    ee_error(int code, const char *str)
{
    write(2, str, strlen(str));
    exit(code);
}
