#include "../minirt.h"

t_float3 ft_get_light_position(t_list_minirt *light)
{
	t_float3 rt;
	rt.x = light->content->parser_light.l_p_x;
	rt.y = light->content->parser_light.l_p_y;
	rt.z = light->content->parser_light.l_p_z;
	return (rt);
}
