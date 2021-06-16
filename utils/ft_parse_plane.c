#include "../minirt.h"


t_parser_global *ft_parse_plane(char *line)
{

	t_parser_global *content;

	content = (t_parser_global*)ft_calloc(sizeof(t_parser_global),1);
	ft_init_parser_global(content);
	content->parser_plane.pl = 1;
	line+=2;
	content->parser_plane.pl_x = ft_atof_retpos(&line);
	line++;
	content->parser_plane.pl_y = ft_atof_retpos(&line);
	line++;
	content->parser_plane.pl_z = ft_atof_retpos(&line);
	line++;
	content->parser_plane.pl_n_vector_x = ft_atof_retpos(&line);
	line++;
	content->parser_plane.pl_n_vector_y = ft_atof_retpos(&line);
	line++;
	content->parser_plane.pl_n_vector_z = ft_atof_retpos(&line);
	line++;
	content->parser_plane.pl_rgb_r = ft_atoi_retpos(&line);
	line++;
	content->parser_plane.pl_rgb_g = ft_atoi_retpos(&line);
	line++;
	content->parser_plane.pl_rgb_b = ft_atoi_retpos(&line);
	return (content);
}
