
t_parser_global *ft_parse_cylinder(char *line)
{

	t_parser_global content;

	content.parser_cylinder.cy = 1;
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
	return (content);
}
