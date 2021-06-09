#include "../minirt.h"

void ft_check_resol(int j, t_parser_resolution *parser_resolution, char *(*lineadress)[LINES])
{
	char *str;

	str = (*lineadress)[--j - 1];
	if (parser_resolution->r == 1)
	{
		while (j > 1 && str[0] != 'R')	
			str = (*lineadress)[--j - 1];
		str++;
		parser_resolution->r_w = ft_atoi_retpos(&str);
		parser_resolution->r_h = ft_atoi_retpos(&str);
	}
	else if (parser_resolution->r == 0)
		return ;
	else
		ft_error_met(lineadress, "Error: Too may R", j);
}

