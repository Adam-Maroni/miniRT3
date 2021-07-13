#include "../minirt.h"

float ft_closest_intersection(t_float3 origin, t_float3 direction, float tmin, float tmax, t_list_minirt *head, t_list_minirt **closest_shape)
{
	float closest_t;
	t_list_minirt *current_shape;
	t_float2 *solutions;

	closest_t = (float)INFINITY;
	current_shape = NULL;
	solutions =  NULL;
	while ((current_shape = ft_find_next_shape(current_shape, head)))
	{
		if (ft_is_a_sphere(current_shape))
			solutions = ft_intersect_ray_with_sphere(origin, direction, ft_get_shape_center(current_shape), current_shape);
		else if (ft_is_a_plane(current_shape))
			solutions = ft_intersect_ray_with_plane(origin, direction, ft_get_shape_center(current_shape), ft_get_shape_normal);
/*
		else if (ft_is_cylinder(current_object))
			solutions = ft_intersect_ray_with_cylinder();
*/
		//We should create a function for this
		if (solutions->t1 >= tmin && solutions->t1 <= tmax && solutions->t1 < closest_t)
		{
			closest_t = solutions->t1;
			*closest_shape = current_shape;
		}
		if (solutions->t2 >= tmin && solutions->t2 <= tmax && solutions->t2 < closest_t)
		{
			closest_t = solutions->t2;
			*closest_shape = current_shape;
		}
		//-------------------------------------
	}
	free(solutions);
	return (closest_t);
}
