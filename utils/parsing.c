#include "../minirt.h"


void ft_fill_parser_structure(char **line, t_parser_global *parser_global)
{
	char *str;

	str = *line;
	if (str[0] == 'R' && ft_isspace((int)(str[1])))
		parser_global->parser_resolution.r++;
	else if (str[0] == 'A' && ft_isspace((int)(str[1])))
		parser_global->parser_ambient.a++;
	else if (str[0] == 'c' && ft_isspace((int)(str[1])))
		parser_global->parser_camera.c++;
	else if (str[0] == 'l' && ft_isspace((int)(str[1])))
		parser_global->parser_light.l++;
	else if (str[0] == 'p' && str[1] == 'l' && ft_isspace((int)(str[2])))
		parser_global->parser_plane.pl++;
	else if (str[0] == 's' && str[1] == 'p' && ft_isspace((int)(str[2])))
		parser_global->parser_sphere.sp++;
	else if (str[0] == 's' && str[1] == 'q' && ft_isspace((int)(str[2])))
		parser_global->parser_square.sq++;
	else if (str[0] == 'c' && str[1] == 'y' && ft_isspace((int)(str[2])))
		parser_global->parser_cylinder.cy++;
	else if (str[0] == 't' && str[1] == 'r' && ft_isspace((int)(str[2])))
		parser_global->parser_triangle.tr++;
	else
		printf("Probleme!!!!!!!!!\n");	
}





void ft_read_from_file(char *filepath, t_parser_global *parser_global, char *(*lineaddress)[LINES], int *j)
{
	char *line;
	int fd;

	line = 0;
	fd = open(filepath, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_fill_parser_structure(&line, parser_global);
		//printf("%s\n", line);
		(*lineaddress)[*j - 1] = line; //A la place de ce pointeur, ajouter une liste chainee
		(*j)++;
	}
	free(line);
	close(fd);
}


void ft_parsing(t_parser_global *parser_global, char *file)
{
	char *lineaddress[LINES];
	int j = 1;

	ft_init_parser_global(parser_global);
	ft_read_from_file(file, parser_global, &lineaddress, &j);
	ft_check_resol(j, &(parser_global->parser_resolution), &lineaddress);
	ft_check_ambient(j, &(parser_global->parser_ambient), &lineaddress);
	ft_check_camera(j, &(parser_global->parser_camera), &lineaddress);
	ft_check_light(j, &(parser_global->parser_light), &lineaddress);
	ft_check_cylinder(j, &(parser_global->parser_cylinder), &lineaddress);
	ft_check_plane(j, &(parser_global->parser_plane), &lineaddress);
	ft_check_sphere(j, &(parser_global->parser_sphere), &lineaddress);
	ft_check_square(j, &(parser_global->parser_square), &lineaddress);
	ft_check_triangle(j, &(parser_global->parser_triangle), &lineaddress);
	ft_free_lineaddress(&lineaddress, j);
}


