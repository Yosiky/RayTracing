#ifndef LIGHT_H
# define LIGHT_H

# include "vector3.h"
# include "ee_list.h"
# include "stddef.h"

typedef unsigned int uint;

typedef enum    e_TYPE_LIGHT
{
    AMBIENT = 0,
    POINT,
    DERECTIONAL
}   t_TYPE_LIGHT;

typedef struct s_light
{
    enum e_TYPE_LIGHT   type;
    double               intensity;
    t_vector3           position;
}   t_light;

uint get_light_type(t_eelist *lst);
t_eelist    *get_light_all(t_eelist *lst);

#endif
