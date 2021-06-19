#include "../minirt.h"

t_float3 *ft_calculate_viewport(t_list_minirt *camera)
{
	t_float3 *viewport = (t_float3*)ft_calloc(sizeof(t_float3),1);
	
	int hypothenuse = camera->content->parser_camera.c_pov_z / cos(ft_deg_to_rad(camera->content->parser_camera.c_fov/2));
	viewport->x = 2 * sqrt(hypothenuse * hypothenuse - camera->content->parser_camera.c_pov_z * camera->content->parser_camera.c_pov_z);
	viewport->y = viewport->x;
	viewport->z = camera->content->parser_camera.c_pov_z;
	return (viewport);
}
