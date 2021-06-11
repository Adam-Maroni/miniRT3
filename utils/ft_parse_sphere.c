#include "../minirt.h"


t_parser_global *ft_parse_sphere(char *line)
{

	t_parser_global content;
	t_parser_global *rt;
	
	rt = NULL;
	ft_init_parser_global(&content);	
	content.parser_sphere.sp = 1;
	line++;
	content.parser_sphere.sp_x = ft_atof_retpos(&line);
	line++;
	content.parser_sphere.sp_y = ft_atof_retpos(&line);
	line++;
	content.parser_sphere.sp_z = ft_atof_retpos(&line);
	line++;
	content.parser_sphere.sp_d = ft_atof_retpos(&line);
	line++;
	content.parser_sphere.sp_rgb_r = ft_atoi_retpos(&line);
	line++;
	content.parser_sphere.sp_rgb_g = ft_atoi_retpos(&line);
	line++;
	content.parser_sphere.sp_rgb_b = ft_atoi_retpos(&line);
	rt = &content;
	return (rt);
}
