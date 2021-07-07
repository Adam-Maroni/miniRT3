#include "../minirt.h"

int ft_traceray(t_list_minirt *camera, t_float3 direction, float tmin, float tmax, t_list_minirt *head, t_color *background_color)
{
	t_list_minirt *closest_shape = NULL;
	float closest_t;
	t_float3 n,p;
	t_float3 shape_position;
	t_color rt_color;

        closest_t = ft_closest_intersection(ft_get_camera_position(camera),direction,tmin,tmax,head, &closest_shape);
	if (closest_shape == NULL)
		return ((int)ft_t_color_to_ul(background_color));
	//The following calculus seems to be the same doesn't matter the kind of shape
	shape_position = ft_get_shape_center(closest_shape);
	p = ft_float3_plus_float3( ft_get_camera_position(camera), ft_float_times_float3(closest_t, direction) );
	n = ft_float3_minus_float3( p, shape_position );
	n = ft_float_times_float3( 1 / ft_get_norm(n) , n );
	rt_color = ft_float_times_t_color(ft_get_shape_color(closest_shape, background_color), ft_compute_lighting(p,n,head,tmin, tmax));
	return ((int)ft_t_color_to_ul(&rt_color));
}

