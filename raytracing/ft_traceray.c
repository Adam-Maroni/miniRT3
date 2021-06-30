#include "../minirt.h"

int ft_traceray(t_list_minirt *camera, t_float3 *direction, float tmin, float tmax, t_list_minirt *head, t_color *background_color)
{
	t_list_minirt *closest_sphere = NULL;
	float closest_t = (float)INFINITY;
	t_float3 p;
	t_float3 n;
	t_color tmp;

	closest_t = ft_closest_intersection(camera,direction,tmin,tmax,head, &closest_sphere);
	if (closest_sphere == NULL)
		return ((int)(ft_t_color_to_ul(background_color)));
	p = ft_get_camera_position(camera);
	n = ft_float_times_float3(closest_t, direction);
	p = ft_float3_plus_float3(&p, &n);//compute intersection
	t_float3 sphere_center = ft_get_sphere_center(closest_sphere);
	n = ft_float3_minus_float3(&p,&sphere_center);
	n = ft_float_times_float3((1/ft_get_norm(&n)), &n);
	tmp = ft_float_times_t_color(ft_get_sphere_color(closest_sphere),ft_compute_lighting(&p,&n,head,camera, direction, tmin, tmax));
	return ((int)(ft_t_color_to_ul(&tmp)));
}




