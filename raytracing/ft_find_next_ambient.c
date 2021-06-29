#include "../minirt.h"

t_list_minirt *ft_find_next_ambient(t_list_minirt *previous_light, t_list_minirt *head)
{
	t_list_minirt *lst;	

	if (!previous_light)
		lst = head;
	else
		lst = previous_light->next;
	while (lst)
	{
		if (lst->content->parser_ambient.a == 1)
			break;
		lst = lst->next;
	}
	return (lst);
}
