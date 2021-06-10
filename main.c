#include "minirt.h"

typedef char (*t_lineaddress)[LINES];


/*
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
*/



int ft_check_square(char *line)
{

	t_parser_global content;
	if (line[0] == 'p' && line[1] == 'l' && ft_isspace((int)(line[2])))
	{
		line++;

int ft_check_cylinder(char *line)
{

	t_parser_global content;
	if (line[0] == 'c' && line[1] == 'y' && ft_isspace((int)(line[2])))
	{
		line++;
		content.parser_cylinder.cy_x = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_y = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_z = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_nvector_x = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_nvector_y = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_nvector_z = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_d = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_h = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_rgb_r = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_rgb_g = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_rgb_b = ft_atof_retpos(&line);

		if ((content.parser_cylinder.cy_rgb_r < 0 || content.parser_cylinder.cy_rgb_r > 255)
		|| (content.parser_cylinder.cy_rgb_g < 0 || content.parser_cylinder.cy_rgb_g > 255)
		|| (content.parser_cylinder.cy_rgb_b < 0 || content.parser_cylinder.cy_rgb_b > 255)
		|| (content.parser_cylinder.cy_n_vector_x < -1 || content.parser_cylinder.cy_n_vector_x > 1)
		|| (content.parser_cylinder.cy_n_vector_y < -1 || content.parser_cylinder.cy_n_vector_y > 1)
		|| (content.parser_cylinder.cy_n_vector_z < -1 || content.parser_cylinder.cy_n_vector_z > 1))
			return (0);
		return (1)
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_list_minirt *head = NULL;
	if (argc != 2)
		ft_terminate_with_error("Trop d'argument passe en parametre", NULL, NULL, NULL);
	head = ft_parsing(argv[1]);
	ft_lstclear_minirt(&head, &ft_del_node_lstminirt);
	return (0);
}








