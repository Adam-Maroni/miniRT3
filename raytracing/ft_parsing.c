#include "../minirt.h"

t_list_minirt *ft_parsing(char *filepath)
{
	char *lineaddress[LINES];
	int	j;
	int fd;
	t_list_minirt *head;
	t_parser_global *parser;

	j = 0;
	head = NULL;
	parser = NULL;
	ft_init_lineaddress(&lineaddress);
	if (!(fd = open(filepath, O_RDONLY)))
		ft_terminate_with_error("Le fichier n'existe pas ou n'est pas lisible.", NULL, NULL, NULL);
	while (get_next_line(fd, &lineaddress[j]))
	{
		if (ft_is_line_correct(lineaddress[j]))
			parser = ft_parse_line(lineaddress[j], ft_is_line_correct(lineaddress[j]));
		else
			ft_terminate_with_error("Fichier invalide.",&lineaddress,&head,&ft_del_node_lstminirt);
		if (parser)
			ft_lstadd_back_minirt(&head,ft_lstnew_minirt(parser));
		j++;
	}
	close(fd);
	ft_free_lineaddress(&lineaddress);
	return (head);
}
