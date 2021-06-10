
t_parser_global *ft_parse_camera(char *line)
{

	t_parser_global content;
	
	content.parser_camera.c = 1;
	line++;
	content.parser_camera.c_pov_x = ft_atof_retpos(&line);
	line++;
	content.parser_camera.c_pov_y = ft_atof_retpos(&line);
	line++;
	content.parser_camera.c_pov_z = ft_atof_retpos(&line);
	line++;
	content.parser_camera.c_n_vector_x = ft_atof_retpos(&line);
	line++;
	content.parser_camera.c_n_vector_y = ft_atof_retpos(&line);
	line++;
	content.parser_camera.c_n_vector_z = ft_atof_retpos(&line);
	line++;
	content.parser_camera.fov = ft_atoi_retpos(&line);
	return (content);
}
