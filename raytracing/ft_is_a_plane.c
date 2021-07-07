#include "../minirt.h"


int ft_is_a_plane(t_list_minirt *lst)
{
	if (lst->content->parser_plane.pl == 1)
		return (1);
	return (0);
}
