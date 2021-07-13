#include "../minirt.h"

t_float2 *ft_intersect_ray_with_plane(t_float3 origin, t_float3 direction, t_float3 center, t_float3 normal)
{
	t_float2 *solutions;

	solutions = (t_float2*)ft_calloc(sizeof(t_float2),1);
	solutions->t2 = (float)INFINITY;
	solutions->t1 = ft_dot_product(ft_float3_minus_float3(center,origin),normal) / ft_dot_product(direction, normal);
	return (solutions);
}


