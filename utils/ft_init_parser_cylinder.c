#include "../minirt.h"

void ft_init_parser_cylinder(t_parser_cylinder *parser_cylinder)
{
	parser_cylinder->cy = 0;
	parser_cylinder->cy_x = 0;
	parser_cylinder->cy_y = 0;
	parser_cylinder->cy_z = 0;
	parser_cylinder->cy_n_vector_x = 0;
	parser_cylinder->cy_n_vector_y = 0;
	parser_cylinder->cy_n_vector_z = 0;
	parser_cylinder->cy_d = 0;
	parser_cylinder->cy_h = 0;
}

