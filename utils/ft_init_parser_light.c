#include "../minirt.h"

void ft_init_parser_light(t_parser_light *parser_light)
{
	parser_light->l = 0;
	parser_light->l_p_x = 0;
	parser_light->l_p_y = 0;
	parser_light->l_p_z = 0;
	parser_light->l_r = 0;
	parser_light->l_rgb_r = 0;
	parser_light->l_rgb_g = 0;
	parser_light->l_rgb_b = 0;
}
