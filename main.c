#include "minirt.h"




/*
int ft_check_triangle(char *line)
{

	t_parser_global content;
	if (line[0] == 'p' && line[1] == 'l' && ft_isspace((int)(line[2])))
	{
		line++;
		content.parser_triangle.tr_x = ft_atof_retpos(&line);
		line++;
		content.parser_triangle.tr_y = ft_atof_retpos(&line);
		line++;
		content.parser_triangle.tr_z = ft_atof_retpos(&line);
		line++;
		content.parser_triangle.tr_rgb_r = ft_atoi_retpos(&line);
		line++;
		content.parser_triangle.tr_rgb_g = ft_atoi_retpos(&line);
		line++;
		content.parser_triangle.tr_rgb_b = ft_atoi_retpos(&line);
		line++;
		content.parser_triangle.tr_n_vector_x = ft_atof_retpos(&line);
		line++;
		content.parser_triangle.tr_n_vector_y = ft_atof_retpos(&line);
		line++;
		content.parser_triangle.tr_n_vector_z = ft_atof_retpos(&line);

				if ((content.parser_triangle.tr_rgb_r < 0 || content.parser_triangle.tr_rgb_r > 255)
				|| (content.parser_triangle.tr_rgb_g < 0 || content.parser_triangle.tr_rgb_g > 255)
				|| (content.parser_triangle.tr_rgb_b < 0 || content.parser_triangle.tr_rgb_b > 255))
				|| (content.parser_triangle.tr_n_vector_x < -1 || content.parser_triangle.tr_n_vector_x > 1)
				|| (content.parser_triangle.tr_n_vector_y < -1 || content.parser_triangle.tr_n_vector_y > 1)
				|| (content.parser_triangle.tr_n_vector_z < -1 || content.parser_triangle.tr_n_vector_z > 1)
				return (0);
		return (1);
	}
	return (0);
}
*/

/*
t_parser_global ft_parse_triangle(char *line)
{

	t_parser_global content;

	content.parser_triangle.tr = 1;
	line++;
	content.parser_triangle.tr_x = ft_atof_retpos(&line);
	line++;
	content.parser_triangle.tr_y = ft_atof_retpos(&line);
	line++;
	content.parser_triangle.tr_z = ft_atof_retpos(&line);
	line++;
	content.parser_triangle.tr_rgb_r = ft_atoi_retpos(&line);
	line++;
	content.parser_triangle.tr_rgb_g = ft_atoi_retpos(&line);
	line++;
	content.parser_triangle.tr_rgb_b = ft_atoi_retpos(&line);
	line++;
	content.parser_triangle.tr_n_vector_x = ft_atof_retpos(&line);
	line++;
	content.parser_triangle.tr_n_vector_y = ft_atof_retpos(&line);
	line++;
	content.parser_triangle.tr_n_vector_z = ft_atof_retpos(&line);
	return (content);
}
*/

int ft_is_line_correct(char *line)
{
	if (ft_check_resolution(line))
		return (1);
	if (ft_check_ambient(line))
		return (2);
	if (ft_check_camera(line))
		return (3);
	if (ft_check_cylinder(line))
		return (4);
	if (ft_check_light(line))
		return (5);
	if (ft_check_plane(line))
		return (6);
	if (ft_check_sphere(line))
		return (7);
	return (0);
}


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


int main(int argc, char **argv)
{
	t_list_minirt *head = NULL;
	if (argc != 2)
		ft_terminate_with_error("Trop d'argument passe en parametre", NULL, NULL, NULL);
	head = ft_parsing(argv[1]);
	if (!ft_check_for_mandatory(&head))
		ft_terminate_with_error("Les elements obligatoires ne sont pas presents.",NULL,&head, &ft_del_node_lstminirt);
	if (ft_check_for_duplicate(&head))
		ft_terminate_with_error("Presence de doublons.",NULL,&head, &ft_del_node_lstminirt);
	ft_raytracing(head);
	ft_lstclear_minirt(&head, &ft_del_node_lstminirt);
	printf("FICHIER VALIDE\n");
	return (0);
}








