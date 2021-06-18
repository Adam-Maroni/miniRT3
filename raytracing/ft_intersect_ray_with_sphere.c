#include "../minirt.h"

t_int2 *ft_intersect_ray_with_sphere(t_parser_camera *camera, t_int3 *point, t_parser_sphere *sphere)
{
	t_int3 camera_to_sphere;
	t_int2 *solutions = (t_int2*)ft_calloc(sizeof(t_int2),1);
	camera_to_sphere.x = sphere.sp_x - camera.pov_x;
	camera_to_sphere.y = sphere.sp_y - camera.pov_y;
	camera_to_sphere.z = sphere.sp_z - camera.pov_z;
	int a = ft_dot_product(point,point);
	int b = 2 * ft_dot_product(camera_to_sphere, point);
	int c = ft_dot_product(camera_to_sphere, camera_to_sphere) - camera.r * camera.r;
	int delta = (b * b) - (4 * a * c);
	if (delta < 0)
	{
		solutions->t1 = INFINITY;
		solutions->t2 = INFINITY;
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

