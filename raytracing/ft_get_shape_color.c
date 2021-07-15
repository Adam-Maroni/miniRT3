#include "../minirt.h"

t_color *ft_get_shape_color(t_list_minirt *shape, t_color *background_color)
{
	
	if (ft_is_a_sphere(shape))
		return (ft_get_sphere_color(shape));
	if (ft_is_a_plane(shape))
		return (ft_get_plane_color(shape));
	if (ft_is_a_cylinder(shape))
		return (ft_get_cylinder_color(shape));
	return (background_color);
}
