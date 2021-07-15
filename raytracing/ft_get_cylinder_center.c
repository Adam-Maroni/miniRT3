#include "../minirt.h"

t_float3 ft_get_cylinder_center(t_list_minirt *cylinder)
{
	t_float3 rt;

	rt.x = cylinder->content->parser_cylinder.cy_x;
	rt.y = cylinder->content->parser_cylinder.cy_y;
	rt.z = cylinder->content->parser_cylinder.cy_z;
	return (rt);
}
