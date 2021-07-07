#include "../minirt.h"

t_list_minirt *ft_find_next_shape(t_list_minirt *previous_shape, t_list_minirt *head)
{
	t_list_minirt *lst;	
	
	if (!previous_shape)
		lst = head;
	else
		lst = previous_shape->next;
	while (lst)
	{
		if(ft_is_a_shape(lst))
			break;
		lst = lst->next;
	}
	return (lst);
}
