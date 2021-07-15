#include "../minirt.h"

t_float3 ft_get_shape_center(t_list_minirt *shape)
{
	t_float3 rt;
	
	rt.x = 0;
	rt.y = 0;
	rt.z = 0;
	if (ft_is_a_sphere(shape))
		return (ft_get_sphere_center(shape));	
	if (ft_is_a_plane(shape))
		return (ft_get_plane_center(shape));	
	if (ft_is_a_cylinder(shape))
		return (ft_get_cylinder_center(shape));	
	return (rt);
}
