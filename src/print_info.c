#include "miniRT.h"

static void    print_sphere(void *ptr)
{
	t_sphere    *obj = (t_sphere *)ptr;
	
	printf("sphere\n");
	printf("\tcenter = ");
	vector3_print(&obj->center);
	printf("\tradius = %lf\n", obj->r);
}

static void    print_plane(void *ptr)
{
	t_plane    *obj = (t_plane *)ptr;

	printf("plane\n");
	printf("\tcenter = ");
	vector3_print(&obj->point);
	printf("\n\tnormal = ");
	vector3_print(&obj->normal);
	printf("\n");
}

static void    print_cylinder(void *ptr)
{
	t_cylinder    *obj = (t_cylinder *)ptr;

	printf("cylinder\n");
	printf("\tpoint = ");
	vector3_print(&obj->center);
	printf("\n\tnormal = ");
	vector3_print(&obj->normal);
	printf("\n\tr = %lf\n", obj->r);
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

void    print_camera(t_camera *obj)
{
	printf("camera:\n\tcoordinate = ");
	vector3_print(&obj->coordinate);
	printf("\n\tnormal = ");
	vector3_print(&obj->normal);
	printf("\n\trotate_x = %d\n\trotate_y = %d\n", obj->rotate_x, obj->rotate_y);
	printf("\tview  = %d\n", obj->view);
}
