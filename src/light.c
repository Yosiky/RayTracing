#include "light.h"

uint get_light_type(t_eelist *lst)
{
    return (((t_light *)lst->data)->type);
}

t_eelist    *get_light_all(t_eelist *lst)
{
    static t_eelist *res;

    if (lst != NULL)
        res = lst;
    return (res);
}

