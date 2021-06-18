#include "../minirt.h"

t_list_minirt *ft_find_next_sphere(t_list_minirt *previous_sphere, t_list_minirt *head)
{
	t_list_minirt *lst;	

	if (!previous_sphere)
		lst = head;
	else
		lst = previous_sphere->next;
	while (lst)
	{
		if (lst->content->parser_sphere.sp == 1)
			break;
		lst = lst->next;
	}
	return (lst);
}
