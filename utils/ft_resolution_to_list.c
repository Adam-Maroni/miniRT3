#include "minirt.h"

t_parser_global ft_parsing_resolution(char *line)
{
	t_parser_global *content;
	int width;
	int height;

	ft_init_parser_global(content);
	line++;
	width = ft_atoi_retpos(line);
	height = ft_atoi_retpos(line);
	content->parser_resolution.r = 1;
	content->parser_resolution.r_w = width;
	content->parser_resolution.r_h = height;
	return (content);
}
