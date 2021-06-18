#include "../minirt.h"

t_list_minirt	*ft_look_for_camera(t_list_minirt *lst)
{
	while (lst)
	{
		if (lst->content->parser_camera.c == 1)
			break ;
		lst = lst->next;
	}
	return (lst);
}
