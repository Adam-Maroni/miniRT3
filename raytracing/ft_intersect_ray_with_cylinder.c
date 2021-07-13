#include "../minirt.h"

t_float2 *ft_intersect_ray_with_cylinder(t_float3 origin, t_float3 direction, t_list_minirt *cylinder)
{
	t_float3 normal;
	t_float3 center;
	t_float2 *solutions;
	t_float2 *tmp1;
	t_float2 *tmp2;
	float radius;
	float height;
	float t;
	float t_prime;
	float ti1;
	float ti2;

	ti1 = 0;
	ti2 = 0;
	normal = ft_get_shape_normal(cylinder);
	center = ft_get_shape_center(cylinder);
	radius = ft_get_shape_radius(cylinder);
	height = cylinder->content->parser_cylinder.cy_h;
	//Intersect with caps
	tmp1 = ft_intersect_ray_with_disk(origin, direction, center, normal, radius);
	tmp2 = ft_intersect_ray_with_disk(origin, direction, ft_float3_plus_float3(center, ft_float_times_float3(height, normal)), normal, radius);
	solutions->t1 = tmp1.t1;
	solutions->t2 = tmp2.t1;
	free(tmp1);
	free(tmp2);
	if (solutions->t1 < (float)INFINITY || solutions->t2 < (float)INFINITY)
		return (solutions);
	//Intersect with side
	tmp1 = ft_intersect_ray_with_plane(origin, direction, center, normal);
	tmp2 = ft_intersect_ray_with_plane(origin, direction, ft_float3_plus_float3(center, ft_float_times_float3(height, normal)), normal);
	solutions->t1 = tmp1.t1;
	solutions->t2 = tmp2.t1;
	free(tmp1);
	free(tmp2);
	if (solutions->t1 > solutions->t2)
	{
		t = solutions->t1;	
		solutions->t1 = solutions->t2;
		solutions->t2 = t;
	}
		//Check if ray pass by cylinder's normal
	t = solutions->t1;	
	while (t < solutions->t2)
	{
		t_prime = 0;
		while (t_prime < h)
		{
			if (ft_float3_plus_float3(origin, ft_float_times_float3(t, direction)) == ft_float3_plus_float3(center, ft_float_times_float3(t_prime, normal)))
				break ;
			t_prime += 1/1000;
		}
		t += 1/1000;
	}
	//IF it doesnt
	else
	{
		solutions->t1 = (float)INFINITY;
		solutions->t2 = (float)INFINITY;
	}
	return (solutions);
}
