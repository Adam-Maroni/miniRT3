#include "../minirt.h"

float ft_compute_lighting(t_float3 p, t_float3 n, t_list_minirt *head)
{
	//besoin des coordonnées du point d'intersection et de la normal par rapport à ce point
	float i = 0;
	//float shadow_t = 0;
	t_float3 l_dir;
	t_list_minirt *shadow_sphere = NULL;


	t_list_minirt *light = NULL;
	while ((light = ft_find_next_ambient(light, head)))
		i += light->content->parser_ambient.a_r; 
	while ((light = ft_find_next_light(light, head)))
	{
		l_dir = ft_float3_minus_float3(ft_get_light_position(light),p);
		float tmin = 0.001;
		float tmax = 1;
		ft_closest_intersection(p, l_dir, tmin, tmax, head, &shadow_sphere);
		//Shadow Check
		if (shadow_sphere)
			continue;
		float n_dot_l = ft_dot_product(n,l_dir);
		if (n_dot_l > 0)
			i += light->content->parser_light.l_r * n_dot_l / (ft_get_norm(n) * ft_get_norm(l_dir));
	}
	return (i);
}
