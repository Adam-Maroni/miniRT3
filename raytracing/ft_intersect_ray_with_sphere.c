#include "../minirt.h"

t_float2 *ft_intersect_ray_with_sphere(t_list_minirt *camera, t_float3 *point, t_list_minirt *sphere)
{
	t_float3 sphere_to_camera;
	t_float2 *solutions = (t_float2*)ft_calloc(sizeof(t_float2),1);
	sphere_to_camera.x = camera->content->parser_camera.c_pov_x - sphere->content->parser_sphere.sp_x;
	sphere_to_camera.y = camera->content->parser_camera.c_pov_y - sphere->content->parser_sphere.sp_y;
	sphere_to_camera.z = camera->content->parser_camera.c_pov_z - sphere->content->parser_sphere.sp_z;
	float a = ft_dot_product(point,point);
	float b = 2 * ft_dot_product(&sphere_to_camera, point);
	float c = ft_dot_product(&sphere_to_camera, &sphere_to_camera) - ft_square(sphere->content->parser_sphere.sp_d / 2);
	float delta = (b * b) - (4 * a * c);
	/* printf ("%d\n", a);
	printf ("%d\n", b);
	printf ("%d\n", c);
	printf ("%d\n", delta);
	*/
	if (delta < 0)
	{
		solutions->t1 = (int)INFINITY;
		solutions->t2 = (int)INFINITY;
	}
	else
	{
		solutions->t1 = (-b + sqrt(delta)) / (2 * a);
		solutions->t2 = (-b - sqrt(delta)) / (2 * a);
	}
	return (solutions);
}

