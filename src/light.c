#include "light.h"

t_light **get_light_all(t_light **arr)
{
    static t_light  **light;

    if (arr != NULL)
        light = arr;
    return (light);
}
