#ifndef EE_ERROR_H
# define EE_ERROR_H

# include <stdlib.h>
# include <unistd.h>

typedef void    (*t_func_clear_project)(void);

void                    set_func_clear_project(t_func_clear_project arg_func);
g_func_clear_project    get_func_clear_project(void);
void                    ee_exit_default(int arg_number_error);
void                    ee_exit(const char *arg_ptr_str);

#endif  // EE_ERROR_H
