#include "../minirt.h"

int ft_is_line_correct(char *line)
{
	if (ft_check_resolution(line))
		return (1);
	if (ft_check_ambient(line))
		return (2);
	if (ft_check_camera(line))
		return (3);
	if (ft_check_cylinder(line))
		return (4);
	if (ft_check_light(line))
		return (5);
	if (ft_check_plane(line))
		return (6);
	if (ft_check_sphere(line))
		return (7);
	if (ft_is_line_empty(line))
		return (8);
	return (0);
}
