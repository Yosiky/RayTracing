#include "ee_error.h"

t_func_clear_project  g_func_clear_project;

void    set_func_clear_project(t_func_clear_project arg_func) {
    g_func_clear_project = arg_func;
}

g_func_clear_project    get_func_clear_project(void) {
    return (g_func_clear_project);
}

void    ee_exit_default(int arg_number_error) {
    printf("%s\n", strerror(arg_number_error));
    (get_func_clear_project())();
    exit(arg_number_error);
}

void ee_exit(const char *arg_ptr_str) {
    perror(str);
    (get_func_clear_project())();
    exit(arg_number_error);
}
