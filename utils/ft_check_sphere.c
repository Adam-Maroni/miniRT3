#include "../minirt.h"


int ft_check_sphere(char *line)
{

	t_parser_global content;
	if (line[0] == 's' && line[1] == 'p' && ft_isspace((int)(line[2])))
	{
		line+=2;
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

		if ((content.parser_sphere.sp_rgb_r < 0 || content.parser_sphere.sp_rgb_r > 255)
		|| (content.parser_sphere.sp_rgb_g < 0 || content.parser_sphere.sp_rgb_g > 255)
		|| (content.parser_sphere.sp_rgb_b < 0 || content.parser_sphere.sp_rgb_b > 255))
			return (0);
		return (1);
	}
	return (0);
}
