#include "../minirt.h"

t_float2 *ft_intersect_ray_with_plane(t_float3 origin, t_float3 direction, t_list_minirt *plane)
{
	t_float3 n;
	t_float2 *solutions;
	t_float3 p0;

	solutions = (t_float2*)ft_calloc(sizeof(t_float2),1);
	p0 = ft_get_shape_center(plane); //Modif cette fonction
	n = ft_get_plane_normal(plane);
	solutions->t2 = (float)INFINITY;
	solutions->t1 = ft_dot_product(ft_float3_minus_float3(p0,origin),n) / ft_dot_product(direction, n);
	return (solutions);
}


