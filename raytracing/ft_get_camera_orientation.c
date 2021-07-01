#include "../minirt.h"

t_float3 ft_get_camera_orientation(t_list_minirt *camera)
{
	t_float3 rt;
	
	rt.x = camera->content->parser_camera.c_n_vector_x;
	rt.y = camera->content->parser_camera.c_n_vector_y;
	rt.z = camera->content->parser_camera.c_n_vector_z;
	return (rt);
}
