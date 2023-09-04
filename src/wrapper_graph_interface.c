#include "wrapper_graph_interface.h"

t_window_config *g_ptr_window_config;

void set_window_config(t_window_config *arg_ptr_window_config) {
    g_ptr_window_config = arg_ptr_window_config;
}

t_window_config *get_window_config(void) {
    return (g_ptr_window_config);
}

t_window_config *window_init(void) {
    t_window_config *ptr_window_config;

    ptr_window_config = (t_window_config *)malloc(sizeof(t_window_config));
    // todo
    return (ptr_window_config);
}
