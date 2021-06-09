#include "../minirt.h"

void ft_check_ambient(int j, t_parser_ambient *parser_ambient, char *(*lineadress)[LINES])
{
	char *str;

	str = (*lineadress)[--j - 1];
	if (parser_ambient->a == 1)
	{
		while (j > 1 && str[0] != 'A')	
			str = (*lineadress)[--j - 1];
		str++;
		parser_ambient->a_r = ft_atof_retpos(&str);
		str++;
		parser_ambient->a_rgb_r = ft_atoi_retpos(&str);
		str++;
		parser_ambient->a_rgb_g = ft_atoi_retpos(&str);
		str++;
		parser_ambient->a_rgb_b = ft_atoi_retpos(&str);
	}
	else if (parser_ambient->a == 0)
		return ;
	else
		ft_error_met(lineadress, "Error: Too many A", j);
}
