#include "../minirt.h"


int ft_check_resolution(char *line)
{
	int width;
	int height;

	width = 0;
	height = 0;
	if (line[0] == 'R' && ft_isspace((int)(line[1])))
	{
		line++;
		width = ft_atoi_retpos(&line);
		height = ft_atoi_retpos(&line);
		if (width <= 0 || height <= 0)
			return (0);
		return (1);
	}
	return (0);
}
