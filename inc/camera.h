#ifndef CAMERA_H
# define CAMERA_H

# include "vector3.h"

typedef struct s_camera
{
    t_vector3   coordinate;
    t_vector3   normal;
    int         rotate_x;
    int         rotate_y;
    unsigned int        view;
}   t_camera;

t_camera    *get_camera(t_camera *obj);
t_vector3    *get_viewer(t_vector3 *ptr);
int *get_rotate_x(int *ptr);
int *get_rotate_y(int *ptr);

#endif
