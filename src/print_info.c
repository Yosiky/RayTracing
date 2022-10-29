#include "miniRT.h"

static void    print_sphere(void *ptr)
{
    t_sphere    *obj = (t_sphere *)ptr;
    
    printf("sphere\n");
    printf("\tcenter = {%lf, %lf, %lf}\n\tr = %lf\n", obj->center.x, obj->center.y, obj->center.z, obj->r);
}

static void    print_plane(void *ptr)
{
    t_plane    *obj = (t_plane *)ptr;

    printf("plane\n");
    printf("\tcenter = {%lf, %lf, %lf}\n\tnormal = {%lf, %lf, %lf}\n", obj->center.x, obj->center.y, obj->center.z, obj->normal.x, obj->normal.y, obj->normal.z);
}

static void    print_cylinder(void *ptr)
{
    t_cylinder    *obj = (t_cylinder *)ptr;

    printf("cylinder\n");
    printf("\tcenter = {%lf, %lf, %lf}\n\tnormal = {%lf, %lf, %lf}\n\tr = %lf\n", obj->center.x, obj->center.y, obj->center.z, obj->normal.x, obj->normal.y, obj->normal.z, obj->r);
}

typedef void    (*t_func_ptrint)(void *ptr);

void    print_obj(t_object *ptr)
{
    static t_func_ptrint    func[] = {print_sphere, print_plane, print_cylinder};

    printf("type = %u\n", ptr->type);
    printf("color = %06x\n", ptr->color);
    printf("reflective = %lf\n", ptr->reflective);
    printf("specular = %d\n", ptr->specular);
   func[ptr->type](ptr->obj.start);

}
