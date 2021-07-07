#include "../minirt.h"

int ft_is_a_sphere(t_list_minirt *lst)
{
	if (lst->content->parser_sphere.sp == 1)
		return (1);
	return (0);
}
