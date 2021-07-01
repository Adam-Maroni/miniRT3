#include "../minirt.h"


t_float3 ft_canvas_to_viewport(int x, int y, t_list_minirt *camera, t_list_minirt *resolution)
{
	t_float3 rt; 
	/*
	rt = ft_calculate_viewport(camera);
	rt->x = x * rt->x / resolution->content->parser_resolution.r_w;
	rt->y = y * rt->y / resolution->content->parser_resolution.r_h;
	rt->z = rt->z;
	*/


	//On tente de simplifier les calculs avec ca
	if (camera){;}
	rt.x = ((float)x * 1 / resolution->content->parser_resolution.r_w);
	rt.y = ((float)y * 1 / resolution->content->parser_resolution.r_w); //on divise par r_w pour eviter les problemes de resolution de l'image
	rt.z = 1;
	return (rt);
}
