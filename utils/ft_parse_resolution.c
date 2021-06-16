#include "../minirt.h"


t_parser_global *ft_parse_resolution(char *line)
{
	t_parser_global *content;
	int width;
	int height;
	
	content = (t_parser_global*)ft_calloc(sizeof(t_parser_global),1);
	ft_init_parser_global(content);
	line++;
	width = ft_atoi_retpos(&line);
	height = ft_atoi_retpos(&line);
	content->parser_resolution.r = 1;
	content->parser_resolution.r_w = width;
	content->parser_resolution.r_h = height;
	return (content);
}
