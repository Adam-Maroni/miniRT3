#include "../minirt.h"


int ft_check_ambient(char *line)
{

	t_parser_global content;
	if (line[0] == 'A' && ft_isspace((int)(line[1])))
	{
		line++;
		content.parser_ambient.a_r = ft_atof_retpos(&line);
		line++;
		content.parser_ambient.a_rgb_r = ft_atoi_retpos(&line);
		line++;
		content.parser_ambient.a_rgb_g = ft_atoi_retpos(&line);
		line++;
		content.parser_ambient.a_rgb_b = ft_atoi_retpos(&line);

		if ((content.parser_ambient.a_r < 0 || content.parser_ambient.a_r > 1)
		|| (content.parser_ambient.a_rgb_r < 0 || content.parser_ambient.a_rgb_r > 255)
		|| (content.parser_ambient.a_rgb_g < 0 || content.parser_ambient.a_rgb_g > 255)
		|| (content.parser_ambient.a_rgb_b < 0 || content.parser_ambient.a_rgb_b > 255))
			return (0);
		return (1);
	}
	return (0);
}
