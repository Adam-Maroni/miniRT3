#include "../minirt.h"


t_float2 *ft_intersect_ray_with_disk(t_float3 origin, t_float3 direction, t_float3 center, t_float3 normal,  float radius)
{
	t_float2 *solutions;	
	float	dist_center_t;
	
	solutions = ft_intersect_ray_with_plane(origin, direction, center, normal);
	dist_center_t = ft_get_norm(ft_float3_minus_float3(center, ft_float3_plus_float3(origin, ft_float_times_float3(solutions->t1, direction))));
	if (dist_center_t > radius)
		solutions->t1 = (float)INFINITY;
	return (solutions);
}
