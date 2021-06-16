#include "../minirt.h"


t_parser_global *ft_parse_light(char *line)
{

	t_parser_global *content;
	
	
	content = (t_parser_global*)ft_calloc(sizeof(t_parser_global),1);
	ft_init_parser_global(content);
	content->parser_light.l = 1;
	line++;
	content->parser_light.l_p_x = ft_atof_retpos(&line);
	line++;
	content->parser_light.l_p_y = ft_atof_retpos(&line);
	line++;
	content->parser_light.l_p_z = ft_atof_retpos(&line);
	line++;
	content->parser_light.l_r = ft_atof_retpos(&line);
	line++;
	content->parser_light.l_rgb_r = ft_atoi_retpos(&line);
	line++;
	content->parser_light.l_rgb_g = ft_atoi_retpos(&line);
	line++;
	content->parser_light.l_rgb_b = ft_atoi_retpos(&line);
	return (content);
}
