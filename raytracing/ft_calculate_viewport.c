#include "../minirt0h"

t_int3 *ft_calculate_viewport(t_parser_camera *camera)
{
	t_int3 *viewport;	
	
	int hypothenuse = camera.pov_z / cos(ft_deg_to_rad(fov/2));
	viewport.x = 2 * sqrt(hypothenuse * hypothenuse - camera.pov_z * camera.pov_z);
	viewport.y = viewport.x;
	viewport.z = camera.pov_z;
	return (viewport);
}

