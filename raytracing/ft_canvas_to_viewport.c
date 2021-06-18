#include "../minirt.h"


t_int3 ft_canvas_to_viewport(int x, int y, t_parser_camera *camera, t_parser_resolution *resolution)
{
	t_int3 *rt = ft_calculate_viewport(camera);
	
	rt.x = x * rt.x / resolution.w;
	rt.y = y * rt.y / resolution.h;
	rt.z = rt.z
	return (rt);
}
