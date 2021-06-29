#include "../minirt.h"

t_float3 ft_get_camera_position(t_list_minirt *camera)
{
	t_float3 rt;

	rt.x = camera->content->parser_camera.c_pov_x;
	rt.y = camera->content->parser_camera.c_pov_y;
	rt.z = camera->content->parser_camera.c_pov_z;
	return (rt);
}
