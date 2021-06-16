#include "../minirt.h"


t_parser_global *ft_parse_sphere(char *line)
{

	t_parser_global *content;
	
	content = (t_parser_global*)ft_calloc(sizeof(t_parser_global),1);
	ft_init_parser_global(content);	
	content->parser_sphere.sp = 1;
	line+=2;
	content->parser_sphere.sp_x = ft_atof_retpos(&line);
	line++;
	content->parser_sphere.sp_y = ft_atof_retpos(&line);
	line++;
	content->parser_sphere.sp_z = ft_atof_retpos(&line);
	line++;
	content->parser_sphere.sp_d = ft_atof_retpos(&line);
	line++;
	content->parser_sphere.sp_rgb_r = ft_atoi_retpos(&line);
	line++;
	content->parser_sphere.sp_rgb_g = ft_atoi_retpos(&line);
	line++;
	content->parser_sphere.sp_rgb_b = ft_atoi_retpos(&line);
	return (content);
}
