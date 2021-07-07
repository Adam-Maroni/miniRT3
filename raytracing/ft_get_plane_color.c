#include "../minirt.h"

t_color *ft_get_plane_color(t_list_minirt *plane)
{
	t_color *rt;
	rt = (t_color*)ft_calloc(sizeof(t_color),1);
	
	rt->alpha = 0;
	rt->r = plane->content->parser_plane.pl_rgb_r;
	rt->g = plane->content->parser_plane.pl_rgb_g;
	rt->b = plane->content->parser_plane.pl_rgb_b;
	return (rt);
}
