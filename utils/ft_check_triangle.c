#include "../minirt.h"

void ft_check_triangle(int j, t_parser_triangle *parser_triangle, char *(*lineadress)[LINES])
{
	char *str;

	str = (*lineadress)[--j - 1];
	if (parser_triangle->tr == 1)
	{
		while (j > 1 && str[0] != 'c')	
			str = (*lineadress)[--j - 1];
		str++;
		parser_triangle->tr = ft_atof_retpos(&str);
		str++;
		parser_triangle->tr_1_x = ft_atof_retpos(&str);
		str++;
		parser_triangle->tr_1_y = ft_atof_retpos(&str);
		str++;
		parser_triangle->tr_1_z = ft_atof_retpos(&str);
		str++;
		parser_triangle->tr_2_x = ft_atof_retpos(&str);
		str++;
		parser_triangle->tr_2_y = ft_atof_retpos(&str);
		str++;
		parser_triangle->tr_2_z = ft_atof_retpos(&str);
		str++;
		parser_triangle->tr_3_x = ft_atof_retpos(&str);
		str++;
		parser_triangle->tr_3_y = ft_atof_retpos(&str);
		str++;
		parser_triangle->tr_3_z = ft_atof_retpos(&str);
		str++;
		parser_triangle->tr_rgb_r = ft_atof_retpos(&str);
		str++;
		parser_triangle->tr_rgb_g = ft_atof_retpos(&str);
		str++;
		parser_triangle->tr_rgb_b = ft_atof_retpos(&str);

	}
	else if (parser_triangle->tr == 0)
		return ;
	else
		ft_error_met(lineadress, "Error: Too many tr", j);
}




