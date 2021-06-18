#include "../minirt.h"



t_color *ft_get_sphere_color(t_list_minirt *sphere)
{
	t_color *rt;
	rt = (t_color*)ft_calloc(sizeof(t_color),1);
	
	rt->alpha = 255;
	rt->r = sphere->content->parser_sphere.sp_rgb_r;
	rt->g = sphere->content->parser_sphere.sp_rgb_g;
	rt->b = sphere->content->parser_sphere.sp_rgb_b;
	return (rt);
}
