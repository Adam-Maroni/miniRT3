#include "../minirt.h"

t_float3 ft_get_shape_normal(t_list_minirt *shape)
{
	if (ft_is_a_plane(shape))
		return (ft_get_plane_normal(shape));
	//cylinder
	return (ft_get_cylinder_normal(shape));
}
