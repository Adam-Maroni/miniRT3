#include "../minirt.h"



t_float3 ft_get_cylinder_normal(t_list_minirt *cylinder)
{
	t_float3 rt;
	rt.x = cylinder->content->parser_cylinder.cy_n_vector_x;
	rt.y = cylinder->content->parser_cylinder.cy_n_vector_y;
	rt.z = cylinder->content->parser_cylinder.cy_n_vector_z;
	return (rt);
}
