#include "../minirt.h"

int ft_traceray(t_list_minirt *camera, t_float3 *direction, int tmin, int tmax, t_list_minirt *head, t_color *background_color)
{
	t_list_minirt *closest_sphere = NULL;
	int closest_t = (int)INFINITY;
	t_float2 *solutions = NULL;
	t_list_minirt *current_sphere = NULL;
	t_float3 p;
	t_float3 n;

	while ((current_sphere = ft_find_next_sphere(current_sphere, head)))
	{
		solutions = ft_intersect_ray_with_sphere(camera, direction, current_sphere);
		if (solutions->t1 >= tmin && solutions->t1 <= tmax && solutions->t1 < closest_t)
		{
			closest_t = solutions->t1;
			closest_sphere = current_sphere;
		}
		if (solutions->t2 >= tmin && solutions->t2 <= tmax && solutions->t2 < closest_t)
		{
			closest_t = solutions->t2;
			closest_sphere = current_sphere;
		}
	}
	free(solutions);
	if (closest_sphere == NULL)
		return ((int)(ft_t_color_to_ul(background_color)));
	p = ft_get_camera_position(camera);
	n = ft_int_times_float3(closest_t, direction);
	p = ft_float3_plus_float3(&p, &n);//compute intersection
	t_float3 sphere_center = ft_get_sphere_center(closest_sphere);
	n = ft_float3_minus_float3(&p,&sphere_center);
	n = ft_int_times_float3((1/ft_get_norm(&n)), &n);
	return ((int)(ft_t_color_to_ul(ft_get_sphere_color(closest_sphere)) * ft_compute_lighting(&p,&n, head)));
}




