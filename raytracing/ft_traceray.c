#include "../minirt.h"

t_color *ft_traceray(t_list_minirt *camera, t_int3 *point, int tmin, int tmax, t_list_minirt *head, t_color *background_color)
{
	t_list_minirt *closest_sphere = NULL;
	int closest_t = (int)INFINITY;
	t_int2 *solutions = NULL;
	t_list_minirt *current_sphere = NULL;
	t_color *rt = NULL;

	while ((current_sphere = ft_find_next_sphere(current_sphere, head)))
	{
		solutions = ft_intersect_ray_with_sphere(camera, point, current_sphere);
		if (solutions->t1 >= tmin && solutions->t1 <= tmax && solutions->t1 < closest_t)
			closest_t = solutions->t1;
		if (solutions->t2 >= tmin && solutions->t2 <= tmax && solutions->t2 < closest_t)
			closest_t = solutions->t2;
		closest_sphere = current_sphere;
	}
	free(solutions);
	if (closest_sphere == NULL)
		rt = background_color;
	else
		rt = ft_get_sphere_color(closest_sphere);
	return (rt);
}




