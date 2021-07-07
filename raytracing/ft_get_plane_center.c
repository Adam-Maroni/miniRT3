#include "../minirt.h"

t_float3 ft_get_plane_center(t_list_minirt *plane)
{
	t_float3 rt;

	rt.x = plane->content->parser_plane.pl_x;
	rt.y = plane->content->parser_plane.pl_y;
	rt.z = plane->content->parser_plane.pl_z;
	return (rt);
}
