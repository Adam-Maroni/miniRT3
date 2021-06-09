#include "../minirt.h"

void ft_init_parser_global(t_parser_global *parser_global)
{
	ft_init_parser_resolution(&(parser_global->parser_resolution));
	ft_init_parser_ambient(&(parser_global->parser_ambient));
	ft_init_parser_camera(&(parser_global->parser_camera));
	ft_init_parser_light(&(parser_global->parser_light));
	ft_init_parser_sphere(&(parser_global->parser_sphere));
	ft_init_parser_square(&(parser_global->parser_square));
	ft_init_parser_plane(&(parser_global->parser_plane));
	ft_init_parser_cylinder(&(parser_global->parser_cylinder));
	ft_init_parser_triangle(&(parser_global->parser_triangle));
}
