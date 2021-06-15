#include "../minirt.h"


void ft_terminate_with_error(char *message, char *(*lineaddress)[66], t_list_minirt **head, void (*ft_del_node_lstminirt))
{
	if (lineaddress)
		ft_free_lineaddress(lineaddress);
	if (*head)
		ft_lstclear_minirt(head, ft_del_node_lstminirt);
	ft_error_met(message);
}
