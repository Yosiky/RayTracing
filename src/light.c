#include "light.h"

uint get_light_type(t_eelist *lst)
{
    return (((t_light *)lst->data)->type);
}

t_light **get_light_all(t_light **arr)
{
    static t_light  **light;

    if (arr != NULL)
        light = arr;
    return (light);
}
