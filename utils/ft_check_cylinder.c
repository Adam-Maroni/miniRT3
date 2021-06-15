#include "../minirt.h"


int ft_check_cylinder(char *line)
{

	t_parser_global content;
	if (line[0] == 'c' && line[1] == 'y' && ft_isspace((int)(line[2])))
	{
		line+=2;
		content.parser_cylinder.cy_x = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_y = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_z = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_n_vector_x = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_n_vector_y = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_n_vector_z = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_d = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_h = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_rgb_r = ft_atoi_retpos(&line);
		line++;
		content.parser_cylinder.cy_rgb_g = ft_atoi_retpos(&line);
		line++;
		content.parser_cylinder.cy_rgb_b = ft_atoi_retpos(&line);
		if ((content.parser_cylinder.cy_n_vector_x < -1 || content.parser_cylinder.cy_n_vector_x > 1)
		|| (content.parser_cylinder.cy_n_vector_y < -1 || content.parser_cylinder.cy_n_vector_y > 1)
		|| (content.parser_cylinder.cy_n_vector_z < -1 || content.parser_cylinder.cy_n_vector_z > 1)
		|| (content.parser_cylinder.cy_rgb_r < 0 || content.parser_cylinder.cy_rgb_r > 255)
		|| (content.parser_cylinder.cy_rgb_g < 0 || content.parser_cylinder.cy_rgb_g > 255)
		|| (content.parser_cylinder.cy_rgb_b < 0 || content.parser_cylinder.cy_rgb_b > 255))
			return (0);
		return (1);
	}
	return (0);
}
