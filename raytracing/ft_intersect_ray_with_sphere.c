#include "../minirt.h"

t_int2 *ft_intersect_ray_with_sphere(t_list_minirt *camera, t_int3 *point, t_list_minirt *sphere)
{
	t_int3 camera_to_sphere;
	t_int2 *solutions = (t_int2*)ft_calloc(sizeof(t_int2),1);
	camera_to_sphere.x = sphere->content->parser_sphere.sp_x - camera->content->parser_camera.c_pov_x;
	camera_to_sphere.y = sphere->content->parser_sphere.sp_y - camera->content->parser_camera.c_pov_y;
	camera_to_sphere.z = sphere->content->parser_sphere.sp_z - camera->content->parser_camera.c_pov_z;
	int a = ft_dot_product(point,point);
	int b = 2 * ft_dot_product(camera_to_sphere, point);
	int c = ft_dot_product(camera_to_sphere, camera_to_sphere) - ft_square(sphere->content->parser_sphere.sp_d / 2);
	int delta = (b * b) - (4 * a * c);
	if (delta < 0)
	{
		solutions->t1 = (int)INFINITY;
		solutions->t2 = (int)INFINITY;
	}
	if (delta == 0)
	{
		solutions->t1 = -b / (2 * a);
		solutions->t2 = -b / (2 * a);
	}
	if (delta > 0)
	{
		solutions->t1 = (-b + sqrt(delta)) / (2 * a);
		solutions->t2 = (-b - sqrt(delta)) / (2 * a);
	}
	return (solutions);
}

