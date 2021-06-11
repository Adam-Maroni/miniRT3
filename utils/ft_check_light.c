#include "../minirt.h"


int ft_check_light(char *line)
{

	t_parser_global content;
	if (line[0] == 'L' && ft_isspace((int)(line[1])))
	{
		line++;
		content.parser_light.l_p_x = ft_atof_retpos(&line);
		line++;
		content.parser_light.l_p_y = ft_atof_retpos(&line);
		line++;
		content.parser_light.l_p_z = ft_atof_retpos(&line);
		line++;
		content.parser_light.l_r = ft_atof_retpos(&line);
		line++;
		content.parser_light.l_rgb_r = ft_atoi_retpos(&line);
		line++;
		content.parser_light.l_rgb_g = ft_atoi_retpos(&line);
		line++;
		content.parser_light.l_rgb_b = ft_atoi_retpos(&line);
		if ((content.parser_light.l_r < 0 || content.parser_light.l_r > 1)
		|| (content.parser_light.l_rgb_r < 0 || content.parser_light.l_rgb_r > 255)
		|| (content.parser_light.l_rgb_g < 0 || content.parser_light.l_rgb_g > 255)
		|| (content.parser_light.l_rgb_b < 0 || content.parser_light.l_rgb_b > 255))
			return (0);
		return (1);
	}
	return (0);
}
