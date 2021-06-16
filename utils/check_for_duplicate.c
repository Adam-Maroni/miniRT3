#include "../minirt.h"

int ft_check_for_duplicate_resolution(t_list_minirt *head)
{
	int cp;	
	t_list_minirt	*tmp;

	tmp = head;
	cp = 0;
	while (tmp)
	{
		if (tmp->content->parser_resolution.r > 0)
			cp += tmp->content->parser_resolution.r;
		tmp = tmp->next;
	}
	return (cp);
}

int ft_check_for_duplicate_ambient(t_list_minirt *head)
{
	int cp;	
	t_list_minirt	*tmp;

	tmp = head;
	cp = 0;
	while (tmp)
	{
		if (tmp->content->parser_ambient.a > 0)
			cp += tmp->content->parser_ambient.a;
		tmp = tmp->next;
	}
	return (cp);
}

int ft_check_for_duplicate_camera(t_list_minirt *head)
{
	int cp;	
	t_list_minirt	*tmp;

	tmp = head;
	cp = 0;
	while (tmp)
	{
		if (tmp->content->parser_camera.c > 0)
			cp += tmp->content->parser_camera.c;
		tmp = tmp->next;
	}
	return (cp);
}

int ft_check_for_duplicate_light(t_list_minirt *head)
{
	int cp;	
	t_list_minirt	*tmp;

	tmp = head;
	cp = 0;
	while (tmp)
	{
		if (tmp->content->parser_light.l > 0)
			cp += tmp->content->parser_light.l;
		tmp = tmp->next;
	}
	return (cp);
}


int ft_check_for_duplicate(t_list_minirt **head)
{
	if (*head)
	{
		if ((ft_check_for_duplicate_resolution(*head) > 0)
		|| (ft_check_for_duplicate_ambient(*head) > 0)
		|| (ft_check_for_duplicate_camera(*head) > 0)
		|| (ft_check_for_duplicate_light(*head) > 0))
			return (1);
	}
		return (0);
}



