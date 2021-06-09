#include "../minirt.h"

void ft_init_parser_triangle(t_parser_triangle *parser_triangle)
{
	parser_triangle->tr = 0;
	parser_triangle->tr_1_x = 0;
	parser_triangle->tr_1_y = 0;
	parser_triangle->tr_1_z = 0;
	parser_triangle->tr_2_x = 0;
	parser_triangle->tr_2_y = 0;
	parser_triangle->tr_2_z = 0;
	parser_triangle->tr_3_x = 0;
	parser_triangle->tr_3_y = 0;
	parser_triangle->tr_3_z = 0;
	parser_triangle->tr_rgb_r = 0;
	parser_triangle->tr_rgb_g = 0;
	parser_triangle->tr_rgb_b = 0;
}
