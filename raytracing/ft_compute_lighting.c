#include "../minirt.h"

float ft_compute_lighting(t_float3 *p, t_float3 *n, t_list_minirt *head)
{
	//besoin des coordonnées du point d'intersection et de la normal par rapport à ce point
	float i = 0;
	t_float3 l;

	t_list_minirt *light = NULL;
	while ((light = ft_find_next_ambient(light, head)))
		i += light->content->parser_ambient.a_r; 
	while ((light = ft_find_next_light(light, head)))
	{
		l = ft_get_light_position(light);
		l = ft_float3_minus_float3(&l,p);
		int n_dot_l = ft_dot_product(n,&l);
		if (n_dot_l > 0)
			i += light->content->parser_light.l_r * n_dot_l / (ft_get_norm(n) * ft_get_norm(&l));
	}
	return (i);
}
