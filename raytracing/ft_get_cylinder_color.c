#include "../minirt.h"

t_color *ft_get_cylinder_color(t_list_minirt *cylinder)
{
	t_color *rt;
	rt = (t_color*)ft_calloc(sizeof(t_color),1);
	
	rt->alpha = 0;
	rt->r = cylinder->content->parser_cylinder.cy_rgb_r;
	rt->g = cylinder->content->parser_cylinder.cy_rgb_g;
	rt->b = cylinder->content->parser_cylinder.cy_rgb_b;
	return (rt);
}




