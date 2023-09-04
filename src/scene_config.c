#include "scene_config.h"

t_scene_config  *g_ptr_scene_config;

void set_scene_config(t_scene_config *arg_ptr_scene_config) {
    g_ptr_scene_config = arg_ptr_scene_config;
};

t_scene_config *get_scene_config(void) {
    return (g_ptr_scene_config);
}

t_scene_config  *parse(char *ptr_name_scene_config) {
// plan:
//  1. check on NULL pointer
//  2. open file
//  3. count all lines and read them
//  4. parse start view position, lights and figures config.
//  5. fill t_scene_config

    t_scene_config  *ptr_scene_config;

    if (ptr_name_scene_config == NULL) {
        ee_error(/* todo */);
    }

    // todo
    return (ptr_scene_config);
}
