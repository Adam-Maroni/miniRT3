#include "../minirt.h"

t_float2 *ft_intersect_ray_with_sphere(t_float3 origin, t_float3 direction, t_float3 sphere, t_list_minirt *spherelst)
{
	t_float3 sphere_to_origin;
	t_float2 *solutions = (t_float2*)ft_calloc(sizeof(t_float2),1);
	sphere_to_origin = ft_float3_minus_float3(origin, sphere);
	float a = ft_dot_product(direction,direction);
	float b = 2 * ft_dot_product(sphere_to_origin, direction);
	float c = ft_dot_product(sphere_to_origin, sphere_to_origin) - ft_square(spherelst->content->parser_sphere.sp_d / 2);
	float delta = (b * b) - (4 * a * c);
	/* printf ("%d\n", a);
	printf ("%d\n", b);
	printf ("%d\n", c);
	printf ("%d\n", delta);
	*/
	if (delta < 0)
	{
		solutions->t1 = (float)INFINITY;
		solutions->t2 = (float)INFINITY;
	}
	else
	{
		solutions->t1 = (-b + sqrt(delta)) / (2 * a);
		solutions->t2 = (-b - sqrt(delta)) / (2 * a);
	}
	return (solutions);
}

