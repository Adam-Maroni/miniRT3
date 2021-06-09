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
		(*lineaddress)[j] = NULL;
}

void ft_free_lineaddress(char *(*lineaddress)[LINES])
{
	int i;
	
	i = LINES;
	while (--i >= 0)
		free ((*lineaddress)[j]);
	ft_init_lineaddress(lineaddress);
}

t_parser_global	ft_check_line(char *line)
{
	if (ft_check_resolution(line))
		return (ft_parsing_resolution(line));
	//else if (line[0] == 'A' && ft_isspace((int)(line[1])))
	//else if (line[0] == 'c' && ft_isspace((int)(line[1])))
	//else if (line[0] == 'l' && ft_isspace((int)(line[1])))
	//else if (line[0] == 'p' && line[1] == 'l' && ft_isspace((int)(line[2])))
	//else if (line[0] == 's' && line[1] == 'p' && ft_isspace((int)(line[2])))
	//else if (line[0] == 's' && line[1] == 'q' && ft_isspace((int)(line[2])))
	//else if (line[0] == 'c' && line[1] == 'y' && ft_isspace((int)(line[2])))
	//else if (line[0] == 't' && line[1] == 'r' && ft_isspace((int)(line[2])))
	else
		return (NULL);
}

t_list_minirt ft_parsing(char *filepath)
{
	char *lineaddress[LINES];
	int	j;
	
	t_list_minirt *head;
	t_parser_global *content;
	j = 0;
	ft_init_lineaddress(&lineaddress);
	if (!(fd = open(filepath, O_RDONLY)))
		ft_error_met("Le fichier n'existe pas ou n'est pas lisible.");
	while (get_next_line(fd, lineaddress[j]))
		if (!(content = ft_check_line(lineaddress[j])))
			ft_error_met("Le fichier n'est pas valide.");
	ft_free_lineaddress(&lineaddress);
	return (head);
}

 
int main(int argc, char **argv)
{
	if (argc != 2)
		ft_error_met("Trop d'argument passe en parametre");
	ft_parsing(argv[1]);
	return (0);
}
