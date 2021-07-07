#include "../minirt.h"


int ft_is_a_cylinder(t_list_minirt *lst)
{
	if (lst->content->parser_cylinder.cy == 1)
		return (1);
	return (0);
}
