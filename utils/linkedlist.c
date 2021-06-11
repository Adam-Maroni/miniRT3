#include "../minirt.h"

void ft_del_node_lstminirt(void *content)
{
	content = NULL;
	if (!content)
		return ;
	//ft_init_parser_global((t_parser_global*)content);
}

t_list_minirt	*ft_lstlast_minirt(t_list_minirt *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void			ft_lstadd_back_minirt(t_list_minirt **head, t_list_minirt *new)
{
	t_list_minirt *lst;

	if ((lst = ft_lstlast_minirt(*head)) == NULL)
		*head = new;
	else
		lst->next = new;
	new->next = NULL;
}

void	ft_lstadd_front_minirt(t_list_minirt **alst, t_list_minirt *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_lstclear_minirt(t_list_minirt **lst, void (*del)(void*))
{
	t_list_minirt *current;
	t_list_minirt *previous;

	previous = (*lst)->next;
	while (previous)
	{
		current = previous->next;
		ft_lstdelone_minirt(previous, (*del));
		previous = current;
	}
	ft_lstdelone_minirt(*lst, (*del));
	(*lst) = NULL;
}

void	ft_lstdelone_minirt(t_list_minirt *lst, void (*del)(void*))
{
	(*del)(lst->content);
	free(lst);
}

void	ft_lstiter_minirt(t_list_minirt *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}


t_list_minirt			*ft_lstmap_minirt(t_list_minirt *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list_minirt *new_list_minirt;
	t_list_minirt *first_element;

	new_list_minirt = ft_lstnew_minirt((*f)(lst->content));
	first_element = new_list_minirt;
	while (lst)
	{
		lst = lst->next;
		new_list_minirt->next = ft_lstnew_minirt((*f)(lst->content));
		new_list_minirt = new_list_minirt->next;
	}
	(*del)(NULL);
	return (first_element);
}

t_list_minirt	*ft_lstnew_minirt(void *content)
{
	t_list_minirt *new;

	if ((new = (t_list_minirt*)malloc(sizeof(t_list_minirt))) == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize_minirt(t_list_minirt *lst)
{
	int count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
