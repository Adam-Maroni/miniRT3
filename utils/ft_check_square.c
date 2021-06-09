#include "../minirt.h"

void ft_check_square(int j, t_parser_square *parser_square, char *(*lineadress)[LINES])
{
	char *str;

	str = (*lineadress)[--j - 1];
	if (parser_square->sq == 1)
	{
		while (j > 1 && str[0] != 'c')	
			str = (*lineadress)[--j - 1];
		str++;
		parser_square->sq = ft_atof_retpos(&str);
		str++;
		parser_square->sq_x = ft_atof_retpos(&str);
		str++;
		parser_square->sq_y = ft_atof_retpos(&str);
		str++;
		parser_square->sq_z = ft_atof_retpos(&str);
		str++;
		parser_square->sq_nvector_x = ft_atof_retpos(&str);
		str++;
		parser_square->sq_nvector_y = ft_atof_retpos(&str);
		str++;
		parser_square->sq_nvector_z = ft_atof_retpos(&str);
		str++;
		parser_square->sq_sd = ft_atof_retpos(&str);
		str++;
		parser_square->sq_rgb_r = ft_atof_retpos(&str);
		str++;
		parser_square->sq_rgb_g = ft_atof_retpos(&str);
		str++;
		parser_square->sq_rgb_b = ft_atof_retpos(&str);

	}
	else if (parser_square->sq == 0)
		return ;
	else
		ft_error_met(lineadress, "Error: Too many sq", j);
}




