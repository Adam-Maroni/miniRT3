/*
#include "../minirt.h"


int ft_is_a_shape(t_list_minirt *lst)
{
	if (ft_is_a_sphere(lst))
		return (1);
	if (ft_is_a_plan(lst))
		return (1);
	if (ft_is_a_cylinder(lst))
		return (1);
	return (0);	
}

int ft_is_a_sphere(t_list_minirt *lst)
{
	if (lst->content->parser_global->parser_sphere.s == 1)
		return (1);
	return (0);
}
int ft_is_a_plane(t_list_minirt *lst)
{
	if (lst->content->parser_global->parser_plane.pl == 1)
		return (1);
	return (0);
}
int ft_is_a_cylinder(t_list_minirt *lst)
{
	if (lst->content->parser_global->parser_cylinder.cy == 1)
		return (1);
	return (0);
}

t_list_minirt *ft_find_next_shape()
{
	if (!previous_shape)
		lst = head;
	else
		lst = previous_shape->next;
	while (lst)
	{
		if(ft_is_a_shape(lst))
			break;
		lst = lst->next;
	}
	return (lst);
}

float ft_closest_intersection(t_float3 origin, t_float3 direction, float tmin, float tmax, t_list_minirt *head, t_list_minirt **closest_shape)
{
	float closest_t;
	t_list_minirt *current_shape;
	t_float2 *solutions;

	closest_t = (float)INFINITY;
	current_shape = NULL;
	solutions =  NULL;
	while ((current_shape = ft_find_next_shape()))
	{
		if (ft_is_sphere(current_object))
			solutions = ft_intersect_ray_with_sphere();
		else if (ft_is_plane(current_object))
			solutions = ft_intersect_ray_with_plane();
		else if (ft_is_cylinder(current_object))
			solutions = ft_intersect_ray_with_cylinder();
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


//Protoype de nouveau ft_traceray, Prend en entree une direction et renvoie en retour une couleur
int ft_traceray_new()
{
	t_list_minirt *current_object;
	current_object = NULL;

	
}


int ft_traceray()
{
	t_list_minirt *closest_shape = NULL;
	float closest_t;
	t_float3 n,p;
	t_float3 shape_position;

	closest_t = ft_closest_intersection();
	if (closest_shape == NULL)
		return ((int)ft_t_color_to_ul(background_color));
	//The following calculus seems to be the same doesn't matter the kind of shape
	shape_position = ft_get_shape_center(closest_shape);
	p = ft_float3_plus_float3( ft_get_camera_position(camera), ft_float_times_float3(closest_t, direction) );
	n = ft_float3_minus_float3( p, shape_position );
	n = ft_float_times_float3( 1 / ft_get_norm(n) , n );
	return ((int)ft_t_color_to_ul(ft_float_times_t_color(ft_get_shape_color(closest_shape), ft_compute_lighting(p,n,head,tmin, tmax))));
}
*/
