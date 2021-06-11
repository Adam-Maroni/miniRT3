#include "../minirt.h"


int ft_check_plane(char *line)
{

	t_parser_global content;
	if (line[0] == 'p' && line[1] == 'l' && ft_isspace((int)(line[2])))
	{
		line++;
		content.parser_plane.pl_x = ft_atof_retpos(&line);
		line++;
		content.parser_plane.pl_y = ft_atof_retpos(&line);
		line++;
		content.parser_plane.pl_z = ft_atof_retpos(&line);
		line++;
		content.parser_plane.pl_rgb_r = ft_atoi_retpos(&line);
		line++;
		content.parser_plane.pl_rgb_g = ft_atoi_retpos(&line);
		line++;
		content.parser_plane.pl_rgb_b = ft_atoi_retpos(&line);
		line++;
		content.parser_plane.pl_n_vector_x = ft_atof_retpos(&line);
		line++;
		content.parser_plane.pl_n_vector_y = ft_atof_retpos(&line);
		line++;
		content.parser_plane.pl_n_vector_z = ft_atof_retpos(&line);

		if ((content.parser_plane.pl_rgb_r < 0 || content.parser_plane.pl_rgb_r > 255)
		|| (content.parser_plane.pl_rgb_g < 0 || content.parser_plane.pl_rgb_g > 255)
		|| (content.parser_plane.pl_rgb_b < 0 || content.parser_plane.pl_rgb_b > 255)
		|| (content.parser_plane.pl_n_vector_x < -1 || content.parser_plane.pl_n_vector_x > 1)
		|| (content.parser_plane.pl_n_vector_y < -1 || content.parser_plane.pl_n_vector_y > 1)
		|| (content.parser_plane.pl_n_vector_z < -1 || content.parser_plane.pl_n_vector_z > 1))
			return (0);
		return (1);
	}
	return (0);
}
