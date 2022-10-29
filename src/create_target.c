#include "miniRT.h"

void    create_light(const char *str, void *dst)
{
    t_light * const light = (t_light * const)dst;
    char * const    *arg = (char * const *)ft_split(str, ' ');
    const uint      count = (const uint)ee_split_count((char **)arg);
    uint            i;

    if (count != 3 && count != 4)
        ee_error(2, "ERROR: invalid data in file");
    i = 0;
    light->type = get_type_line(arg[i++]) - PARSE_AMBIENT;
    if (light->type == LIGHT_POINT)
        vector3_parse(&light->position, arg[i++]);
    light->intensity = ft_atof(arg[i++]); // todo ft_atof forbidden
    light->color = ee_color_parse(arg[i]);
    ee_split_clear((char **)arg);
}

void    create_camera(const char *str, void *dst)
{
    t_camera *const data = (t_camera *const)dst;
    char *const *arg = (char *const *)ft_split(str, ' ');
    const uint  count = (const uint)ee_split_count((char **)arg);

    if (count != 4)
        ee_error(2, "ERROR: invalid data in file");
    vector3_parse(&data->coordinate, arg[1]);
    vector3_parse(&data->normal, arg[2]);
    vector3_get_degree(&data->rotate_x, &data->rotate_y, &data->normal);
    data->view = (uint)ft_atoi(arg[3]);
    ee_split_clear((char **)arg);
}

void    create_sphere(const char *str, void *dst)
{
    t_object *const data = (t_object *const)dst;
    char *const     *arg = (char *const *)ft_split(str, ' ');
    const uint      count = (const uint)ee_split_count((char **)arg);

    if (count != 4)
        ee_error(2, "ERROR: invalid data in file");
    data->obj.sphere = (t_sphere *)ee_malloc(sizeof(t_sphere));
    vector3_parse(&data->obj.sphere->center, arg[1]);
    data->obj.sphere->r = ft_atof(arg[2]) / 2;
    data->type = OBJ_SPHERE;
    data->reflective = 0;
    data->specular = 0;
    data->color = ee_color_parse(arg[3]);
    ee_split_clear((char **)arg);
}

void    create_plane(const char *str, void *dst)
{
    t_object *const    data = (t_object *const)dst;
    char *const    *arg = (char *const *)ft_split(str, ' ');
    const uint      count = (const uint)ee_split_count((char **)arg);
    t_vector3       a;
    t_vector3       b;

    if (count != 4)
        ee_error(2, "ERROR: invalid data in file");
    data->obj.plane = (t_plane *)ee_malloc(sizeof(t_plane));
    vector3_parse(&data->obj.plane->center, arg[1]);
    vector3_parse(&data->obj.plane->normal, arg[2]);
    data->type = OBJ_PLANE;
    data->specular = 0;
    data->reflective = 0;
    data->color = ee_color_parse(arg[3]);
    ee_split_clear((char **)arg);
    vector3_minus(&a, &data->obj.plane->a, &data->obj.plane->b);
    vector3_minus(&b, &data->obj.plane->c, &data->obj.plane->b);
    vector3_cross(&data->obj.plane->n, &a, &b);
    vector3_normalized(&data->obj.plane->n);
}

void    create_cylinder(const char *str, void *dst)
{
    t_object *const    data = (t_object *const)dst;
    char *const    *arg = (char *const *)ft_split(str, ' ');
    const uint      count = (const uint)ee_split_count((char **)arg);

    if (count != 6)
        ee_error(2, "ERROR: invalid data in file");
    data->obj.cylinder = (t_cylinder *)ee_malloc(sizeof(t_cylinder));
    vector3_parse(&data->obj.cylinder->center, arg[1]);
    vector3_parse(&data->obj.cylinder->normal, arg[2]);
    data->obj.cylinder->r = ft_atof(arg[3]) / 2;
    data->obj.cylinder->hight = ft_atof(arg[4]);
    data->type = OBJ_CYLINDER;
    data->specular = 0;
    data->reflective = 0;
    data->color = ee_color_parse(arg[5]);
}
