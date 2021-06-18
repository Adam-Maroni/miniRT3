#include "../minirt.h"

t_int3 *ft_calculate_viewport(t_parser_camera *camera)
{
	t_int3 *viewport = (t_int3*)ft_calloc(sizeof(t_int3),1);
	
	int hypothenuse = camera->c_pov_z / cos(ft_deg_to_rad(camera->c_fov/2));
	viewport->x = 2 * sqrt(hypothenuse * hypothenuse - camera->c_pov_z * camera->c_pov_z);
	viewport->y = viewport->x;
	viewport->z = camera->c_pov_z;
	return (viewport);
}
