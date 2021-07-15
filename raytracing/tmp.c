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
