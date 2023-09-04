#ifndef WRAPPER_GRAPH_INTERFACE_H
# define WRAPPER_GRAPH_INTERFACE_H

# include "mlx.h"

typedef struct {

} t_window_config;

void set_window_config(t_window_config *arg_ptr_window_config);
t_window_config *get_window_config(void);
t_window_config *window_init(void);

#endif  // WRAPPER_GRAPH_INTERFACE_H
