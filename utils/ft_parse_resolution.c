#include "../minirt.h"


t_parser_global *ft_parse_resolution(char *line)
{
	t_parser_global *content;
	t_parser_global tmp;
	int width;
	int height;
	
	content = &tmp;
	ft_init_parser_global(content);
	line++;
	width = ft_atoi_retpos(&line);
	height = ft_atoi_retpos(&line);
	content->parser_resolution.r = 1;
	content->parser_resolution.r_w = width;
	content->parser_resolution.r_h = height;
	return (content);
}
