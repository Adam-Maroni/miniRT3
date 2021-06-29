#include "../minirt.h"



t_float3 ft_get_sphere_center(t_list_minirt *sphere)
{
	t_float3 rt;

	rt.x = sphere->content->parser_sphere.sp_x;
	rt.y = sphere->content->parser_sphere.sp_y;
	rt.z = sphere->content->parser_sphere.sp_z;
	return (rt);
}
