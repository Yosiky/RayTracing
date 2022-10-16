#include "miniRT.h"

/* void    create_plane(t_object *elem, t_vector3 a, t_vector3 b, t_vector3 c, uint color, uint specular, double ref) */
/* { */
/*     elem->type = 1; */
/*     elem->color = color; */
/*     elem->obj.plane = (t_plane *)malloc(sizeof(t_plane)); */
/*     elem->obj.plane->a = a; */
/*     elem->obj.plane->b = b; */
/*     elem->obj.plane->c = c; */
/*     elem->specular = specular; */
/*     elem->reflective = ref; */
/*     t_vector3   one, two; */

/*     vector3_minus(&one, &a, &b); */
/*     vector3_minus(&two, &c, &b); */

/*     vector3_cross(&elem->obj.plane->n, &one, &two); */
/*     vector3_normalized(&elem->obj.plane->n); */
/* } */

/* void    create_sphere(t_object *elem, t_vector3 c, uint r, uint color, uint specular, double ref) */
/* { */
/*     elem->type = 0; */
/*     elem->color = color; */
/*     elem->specular = specular; */
/*     elem->reflective = ref; */
/*     elem->obj.sphere = (t_sphere *)malloc(sizeof(t_sphere)); */
/*     elem->obj.sphere->r = r; */
/*     elem->obj.sphere->center = c; */
/* } */

/* void    create_cylinder(t_object *elem, t_vector3 center, t_vector3 normal, double hight, double diameter, uint color, uint specular, double ref) */
/* { */
/*     elem->type = 2; */
/*     elem->obj.cylinder = (t_cylinder *)malloc(sizeof(t_cylinder)); */
/*     elem->color = color; */
/*     elem->specular = specular; */
/*     elem->reflective = ref; */
/*     elem->obj.cylinder->center = center; */
/*     elem->obj.cylinder->normal = normal; */
/*     elem->obj.cylinder->r = diameter / 2; */
/*     elem->obj.cylinder->hight = hight; */
/* } */

t_vector3    *get_viewer(t_vector3 *ptr)
{
    static t_vector3 obj = {0, 0, 0};

    if (ptr != NULL)
        obj = *ptr;
    return (&obj);
}

t_object    *get_object(t_object *ptr)
{
    static t_object *obj = NULL;

    if (ptr != NULL)
        obj = ptr;
    return (obj);
}

t_image    *get_image(t_image *ptr)
{
    static t_image *obj = NULL;

    if (ptr != NULL)
        obj = ptr;
    return (obj);
}

t_window    *get_window(t_window *ptr)
{
    static t_window *obj = NULL;

    if (ptr != NULL)
        obj = ptr;
    return (obj);
}

t_mlx    *get_mlx(t_mlx *ptr)
{
    static t_mlx *obj = NULL;

    if (ptr != NULL)
        obj = ptr;
    return (obj);
}
int ee_exit(void)
{
    exit(0);
}

void    init_hook(t_window *ptr_window)
{
    mlx_key_hook(ptr_window->win, event_move, NULL);
    mlx_hook(ptr_window->win, 17, 0, ee_exit, NULL);
}

uint    ee_color_parse(char *str)
{
    uint    dst;
    int     i;
    const uint  ind[] = {16, 8, 0};

    dst = 0;
    i = 2;
    while (i >= 0)
    {
        dst += ft_atoi(str) << ind[i--];
        while (*str != ',' && *str != '\n')
            ++str;
        ++str;
    }
    return (dst);
}

typedef void    (*t_func_creator)(const char *str, void *dst);

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
        light->position = vector3_parse(arg[i++]);
    light->intensity = atof(arg[i++]); // todo atof forbidden
    light->color = ee_color_parse(arg[i]);
    ee_split_clear((char **)arg);
}

void    create_camera(const char *str, void *dst)
{
}

void    create_sphere(const char *str, void *dst)
{
    t_object *const    data = (t_object *const)dst;
    char *const    *arg = (char *const *)ft_split(str, ' ');
    const uint      count = (const uint)ee_split_count((char **)arg);

    if (count != 4)
        ee_error(2, "ERROR: invalid data in file");
    data->obj.sphere = (t_sphere *)ee_malloc(sizeof(t_sphere));
    data->obj.sphere->center = vector3_parse(arg[1]);
    data->obj.sphere->r = atof(arg[2]) / 2;
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
    data->obj.plane->center = vector3_parse(arg[1]);
    data->obj.plane->normal = vector3_parse(arg[2]);
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
    data->obj.cylinder->center = vector3_parse(arg[1]);
    data->obj.cylinder->normal = vector3_parse(arg[2]);
    data->obj.cylinder->r = atof(arg[3]) / 2; // todo
    data->obj.cylinder->hight = atof(arg[4]); // todo
    data->type = OBJ_CYLINDER;
    data->specular = 0;
    data->reflective = 0;
    data->color = ee_color_parse(arg[5]);
}


void    parse_data(t_file *ptr)
{
    static t_func_creator func[] = {create_light, create_light, create_camera, create_sphere, create_plane, create_cylinder};
    int type;
    uint64_t    count[3];
    t_object    *obj;
    t_light     *light;
    int64_t     i;

    count[0] = count_type_in_file(ptr);
    count[1] = count[0] >> 32;
    count[2] = count[0] & 0xffffffff;
    obj = (t_object *)ee_malloc(sizeof(t_object) * (count[1] + 1));
    light = (t_light *)ee_malloc(sizeof(t_light) * (count[2] + 1));
    obj[--count[1]].type = OBJ_NONE;
    light[--count[2]].type = LIGHT_NONE;
    get_object(obj);
    get_light(light);
    i = 0;
    while (i < ptr->count)
    {
        type = get_type_line(ptr->data[i]);
        printf("i = %d, type = %d\n", i, type);
        if (type == PARSE_AMBIENT || type == PARSE_POINT)
            func[type](ptr->data[i], (void *)&light[--count[2]]);
        else if (type == PARSE_CAMERA)
            func[type](ptr->data[i], NULL);
        else if (type > PARSE_CAMERA)
            func[type](ptr->data[i], (void *)&obj[--count[1]]);
        ++i;
    }
}

int main(int argc, char **argv)
{
    t_file  *ptr_file;

    if (argc == 2)
    {
        ptr_file = read_file(argv[1]);
        parse_data(ptr_file);
        t_file_clean(ptr_file);
        t_object *obj = get_object(NULL);
        t_light *light = get_light(NULL);

        t_mlx *ptr_mlx = mlx_init();
        t_window    *ptr_window;
        t_image     *ptr_image;
        if (ptr_mlx == NULL)
            ee_error(1, "Can't init mlx");
        ptr_window = create_window(ptr_mlx, WINDOW_X, WINDOW_Y, WINDOW_NAME);
        ptr_image = create_image(ptr_mlx, IMG_X, IMG_Y);
        init_hook(ptr_window);
        get_image(ptr_image);
        get_window(ptr_window);
        get_mlx(ptr_mlx);
        draw_on_img(ptr_image, get_object(NULL));
        mlx_put_image_to_window(ptr_mlx, ptr_window->win, ptr_image->img, 0, 0);
        mlx_loop(ptr_mlx);
    }
    else
        ee_error(3, "Error: not valid count arg");
    return (0);
}
