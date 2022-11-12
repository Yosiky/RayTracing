#ifndef LIGHT_H
# define LIGHT_H

# include "vector3.h"
# include "ee_list.h"
# include "stddef.h"

typedef unsigned int uint;

enum    e_TYPE_LIGHT
{
    LIGHT_NONE = -1,
    LIGHT_AMBIENT,
    LIGHT_POINT,
    LIGHT_DERECTIONAL
};

typedef struct s_light
{
    enum e_TYPE_LIGHT   type;
    double              intensity;
    t_vector3           position;
    uint                color;
}   t_light;

t_light *get_light(t_light *light);

#endif
