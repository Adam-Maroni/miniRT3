
t_parser_global *ft_parse_line(char *line, int parse_choice)
{
	t_parser_global *content;

	content = NULL;
	if (parse_choice == 1)
		content = ft_parse_resolution(*line);
	if (parse_choice == 2)
		content = ft_parse_ambient(*line);
	if (parse_choice == 3)
		content = ft_parse_camera(*line);
	if (parse_choice == 4)
		content = ft_parse_cylinder(*line);
	if (parse_choice == 5)
		content = ft_parse_light(*line);
	if (parse_choice == 6)
		content = ft_parse_plane(*line);
	if (parse_choice == 7)
		content = ft_parse_sphere(*line);
	return (content);
}
t_parser_global *ft_parse_line(char *line, int parse_choice)
{
	t_parser_global *content;

	content = NULL;
	if (parse_choice == 1)
		content = ft_parse_resolution(*line);
	if (parse_choice == 2)
		content = ft_parse_ambient(*line);
	if (parse_choice == 3)
		content = ft_parse_camera(*line);
	if (parse_choice == 4)
		content = ft_parse_cylinder(*line);
	if (parse_choice == 5)
		content = ft_parse_light(*line);
	if (parse_choice == 6)
		content = ft_parse_plane(*line);
	if (parse_choice == 7)
		content = ft_parse_sphere(*line);
	return (content);
}
