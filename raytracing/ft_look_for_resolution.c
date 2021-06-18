#include "../minirt.h"

t_list_minirt *ft_look_for_resolution(t_list_minirt *lst)
{
	while (lst)
		if (lst->content->parser_resolution.r == 1)
			break ;
		lst = lst->next;
	return (lst);
}
