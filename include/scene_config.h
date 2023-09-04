#ifndef SCENE_CONFIG_H
# define SCENE_CONFIG_H

# include "ee_error.h"
# include "light.h"
# include "sphere.h"

typedef struct {
    void    *ptr_lights_array;
    void    *ptr_figures_array;
} t_scene_config;

void            set_scene_config(t_scene_config *arg_ptr_scene_config);
t_scene_config  *get_scene_config(void);
t_scene_config  *parse(char *ptr_name_scene_config);


#endif  // SCENE_CONFIG_H
