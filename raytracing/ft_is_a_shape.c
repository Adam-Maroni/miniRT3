#include "../minirt.h"

int ft_is_a_shape(t_list_minirt *lst)
{
	if (ft_is_a_sphere(lst))
		return (1);
	if (ft_is_a_plane(lst))
		return (1);
	if (ft_is_a_cylinder(lst))
		return (1);
	return (0);	
}
