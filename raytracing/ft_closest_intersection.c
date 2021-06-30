#include "../minirt.h"



float ft_closest_intersection(t_list_minirt *camera, t_float3 *direction, float tmin, float tmax, t_list_minirt *head, t_list_minirt **closest_sphere)
{
	float closest_t;
	t_list_minirt *current_sphere;
	t_float2 *solutions = NULL;
	
	closest_t = (float)INFINITY;
	current_sphere = NULL;
	while ((current_sphere = ft_find_next_sphere(current_sphere, head)))
	{
		solutions = ft_intersect_ray_with_sphere(camera, direction, current_sphere);
		if (solutions->t1 >= tmin && solutions->t1 <= tmax && solutions->t1 < closest_t)
		{
			closest_t = solutions->t1;
			*closest_sphere = current_sphere;
		}
		if (solutions->t2 >= tmin && solutions->t2 <= tmax && solutions->t2 < closest_t)
		{
			closest_t = solutions->t2;
			*closest_sphere = current_sphere;
		}
	}
	free(solutions);
	return (closest_t);
}
