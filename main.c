#include "minirt.h"



void ft_error_met(char *message)
{
	printf("%s\n", message);
	exit (0);
}


void ft_init_lineaddress(char *(*lineaddress)[LINES])
{
	int i;

	i = -1;
	while (++i < LINES)
		(*lineaddress)[i] = NULL;
}

void ft_free_lineaddress(char *(*lineaddress)[LINES])
{
	int i;

	i = LINES;
	while (--i >= 0)
		free ((*lineaddress)[i]);
	ft_init_lineaddress(lineaddress);
}

int ft_check_resolution(char *line)
{
	int width;
	int height;

	width = 0;
	height = 0;
	if (line[0] == 'R' && ft_isspace((int)(line[1])))
	{
		line++;
		width = ft_atoi_retpos(&line);
		height = ft_atoi_retpos(&line);
		if (width <= 0 || height <= 0)
			return (-1);
		return (1);
	}
	return (0);
}

t_parser_global ft_parsing_resolution(char *line)
{
	t_parser_global content;

	int width;
	int height;


	ft_init_parser_global(&content);
	line++;
	width = ft_atoi_retpos(&line);
	height = ft_atoi_retpos(&line);
	content.parser_resolution.r = 1;
	content.parser_resolution.r_w = width;
	content.parser_resolution.r_h = height;
	return (content);
}




void	ft_check_line(char *line, t_parser_global *content)
{
	if (ft_check_resolution(line))
		*content = ft_parsing_resolution(line);
	else if (ft_check_resolution(line) < 0)
		ft_error_met("Resolution invalide."); //+LIBERER LA MEMOIRE
	//else if (line[0] == 'A' && ft_isspace((int)(line[1])))
	//else if (line[0] == 'c' && ft_isspace((int)(line[1])))
	//else if (line[0] == 'l' && ft_isspace((int)(line[1])))
	//else if (line[0] == 'p' && line[1] == 'l' && ft_isspace((int)(line[2])))
	//else if (line[0] == 's' && line[1] == 'p' && ft_isspace((int)(line[2])))
	//else if (line[0] == 's' && line[1] == 'q' && ft_isspace((int)(line[2])))
	//else if (line[0] == 'c' && line[1] == 'y' && ft_isspace((int)(line[2])))
	//else if (line[0] == 't' && line[1] == 'r' && ft_isspace((int)(line[2])))
	else
		content = NULL;
}

t_list_minirt *ft_parsing(char *filepath)
{
	char *lineaddress[LINES];
	int	j;
	int fd;
	t_list_minirt *head;
	t_parser_global *ptcontent;
	t_parser_global content;

	ptcontent = &content; 
	j = 0;
	head = NULL;
	ft_init_lineaddress(&lineaddress);
	ft_init_parser_global(ptcontent);
	if (!(fd = open(filepath, O_RDONLY)))
		ft_error_met("Le fichier n'existe pas ou n'est pas lisible.");
	while (get_next_line(fd, &lineaddress[j]))
	{
		ft_check_line(lineaddress[j], ptcontent);
		if (!ptcontent)
		{
			ft_lstclear_minirt(&head, &ft_del_node_lstminirt);
			ft_free_lineaddress(&lineaddress);
			ft_error_met("Le fichier n'est pas valide.");
		}
		ft_lstadd_back_minirt(&head,ft_lstnew_minirt(ptcontent));
		j++;
	}
	close(fd);
	ft_free_lineaddress(&lineaddress);
	return (head);
}


int main(int argc, char **argv)
{
	t_list_minirt *head = NULL;
	if (argc != 2)
		ft_error_met("Trop d'argument passe en parametre");
	head = ft_parsing(argv[1]);
	ft_lstclear_minirt(&head, &ft_del_node_lstminirt);
	return (0);
}
