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


t_list_minirt ft_parsing(char *filepath)
{
	char *lineaddress[LINES];
	int	j;
	t_list_minirt	list_minirt;
	
	j = 0;
	ft_init_lineaddress(&lineaddress);
	if (!(fd = open(filepath, O_RDONLY)))
		ft_error_met("Le fichier n'existe pas ou n'est pas lisible.");
	while (get_next_line(fd, lineaddress[j]))
	{
		if (ft_check_line(lineaddress[j]))
			ft_line_to_listminirt(lineaddress, list_minirt);
		else
			ft_error_met("Le fichier n'est pas valide.");
		j++;
	}
	ft_free_lineaddress(&lineaddress);
	return (list_minirt);
}

 
int main(int argc, char **argv)
{
	if (argc != 2)
		ft_error_met("Trop d'argument passe en parametre");
	ft_parsing(argv[1]);
	return (0);
}
