#include "../minirt.h"


int ft_check_camera(char *line)
{

	t_parser_global content;
	if (line[0] == 'C' && ft_isspace((int)(line[1])))
	{
		line++;
		content.parser_camera.c_pov_x = ft_atof_retpos(&line);
		line++;
		content.parser_camera.c_pov_y = ft_atof_retpos(&line);
		line++;
		content.parser_camera.c_pov_z = ft_atof_retpos(&line);
		line++;
		content.parser_camera.c_n_vector_x = ft_atof_retpos(&line);
		line++;
		content.parser_camera.c_n_vector_y = ft_atof_retpos(&line);
		line++;
		content.parser_camera.c_n_vector_z = ft_atof_retpos(&line);
		line++;
		content.parser_camera.c_fov = ft_atoi_retpos(&line);
		if ((content.parser_camera.c_n_vector_x < -1 || content.parser_camera.c_n_vector_x > 1)
		|| (content.parser_camera.c_n_vector_y < -1 || content.parser_camera.c_n_vector_y > 1)
		|| (content.parser_camera.c_n_vector_z < -1 || content.parser_camera.c_n_vector_z > 1)
		|| (content.parser_camera.c_fov < 0 || content.parser_camera.c_fov > 180))
			return (0);
		return (1);
	}
	return (0);
}
