#include "../minirt.h"

void ft_init_parser_camera(t_parser_camera *parser_camera)
{
	parser_camera->c = 0;
	parser_camera->c_pov_x = 0;
	parser_camera->c_pov_y = 0;
	parser_camera->c_pov_z = 0;
	parser_camera->c_n_vector_x = 0;
	parser_camera->c_n_vector_y = 0;
	parser_camera->c_n_vector_z = 0;
	parser_camera->c_fov = 0;
}
