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

typedef void    (*t_func_creator)(const char *str, void *dst);

void    create_light(const char *str, void *dst);
/* { */
/*     char const  **arg = (char const **)ft_split(str, ' '); */

/* } */

void    create_camera(const char *str, void *dst);
void    create_sphere(const char *str, void *dst);
void    create_plane(const char *str, void *dst);
void    create_cylinder(const char *str, void *dst);


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
    obj = (t_object *)ee_malloc(sizeof(t_object) * count[1]);
    light = (t_light *)ee_malloc(sizeof(t_light) * (count[2] + 1));
    get_object(obj);
    get_light(light);
    i = 0;
    while (i < ptr->count)
    {
        type = get_type_line(ptr->data[i]);
        if (type == PARSE_AMBIENT || type == PARSE_POINT)
            func[type](ptr->data[i], (void *)&light[--count[2]]);
        else if (type == PARSE_CAMERA)
            func[type](ptr->data[i], NULL);
        else if (type > PARSE_CAMERA)
            func[type](ptr->data[i], (void *)&obj[--count[1]]);
    }
}

/* int main(void) */
/* { */
/*     t_mlx *ptr_mlx = mlx_init(); */
/*     t_window    *ptr_window; */
/*     t_image     *ptr_image; */

/*     if (ptr_mlx == NULL) */
/*         ee_error(1, "Can't init mlx"); */
/*     ptr_window = create_window(ptr_mlx, WINDOW_X, WINDOW_Y, WINDOW_NAME); */
/*     ptr_image = create_image(ptr_mlx, IMG_X, IMG_Y); */
/*     init_hook(ptr_window); */

/*     t_light light[] = {{LIGHT_AMBIENT, 0.2, {0, 0, 0}}, */
/*                         {LIGHT_POINT, 0.6, {2, 1, 0}}, */
/*                         {LIGHT_DERECTIONAL, 0.2, {1, 4, 4}}, */
/*                         {LIGHT_NONE, 0, {0, 0, 0}}}; */
/*     t_object    *figures = (t_object *)malloc(sizeof(t_object) * 6); */

/*     get_object(figures); */
/*     get_image(ptr_image); */
/*     get_window(ptr_window); */
/*     get_mlx(ptr_mlx); */
/*     create_sphere(&figures[0], (t_vector3){0, -1, 3}, 1, 0x00ff0000, 500, 0.2); */
/*     create_sphere(&figures[1], (t_vector3){2, 0, 4}, 1, 0x000000ff, 500, 0.3); */
/*     create_sphere(&figures[2], (t_vector3){-2, 0, 4}, 1, 0x0000ff00, 10, 1); */
/*     /1* create_sphere(&figures[3], (t_vector3){0, -5001, 0}, 5000, 0x00ffff00, 1000, 0.5); *1/ */
/*     create_plane(&figures[3], (t_vector3){-2, -1, -2}, (t_vector3){0, -1, 0}, (t_vector3){1, -1, 10}, 0x00ffff00, 1000, 0); */
/*     create_plane(&figures[4], (t_vector3){-4, 1, 10}, (t_vector3){-4, 0, 0}, (t_vector3){-4, 0, 4}, 0x00ff00ff, 1000, 0.5); */
/*     figures[5].type = -1; */
/*     vector3_normalized(&light[2].position); */
/*     get_light(light); */
/*     draw_on_img(ptr_image, figures); */
/*     mlx_put_image_to_window(ptr_mlx, ptr_window->win, ptr_image->img, 0, 0); */
/*     mlx_loop(ptr_mlx); */
/*     destroy_window(ptr_mlx, ptr_window); */
/*     destroy_image(ptr_mlx, ptr_image); */
/*     return (0); */
/* } */

int main(int argc, char **argv)
{
    t_file  *ptr_file;


    if (argc == 2)
    {
        ptr_file = read_file(argv[1]);
        parse_data(ptr_file);
        t_file_clean(ptr_file);
    }
    else
        ee_error(3, "Error: not valid count arg");
    return (0);
}
