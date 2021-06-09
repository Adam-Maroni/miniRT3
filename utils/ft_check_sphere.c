#include "../minirt.h"

void ft_check_sphere(int j, t_parser_sphere *parser_sphere, char *(*lineadress)[LINES])
{
	char *str;

	str = (*lineadress)[--j - 1];
	if (parser_sphere->sp == 1)
	{
		while (j > 1 && str[0] != 'c')	
			str = (*lineadress)[--j - 1];
		str++;
		parser_sphere->sp = ft_atof_retpos(&str);
		str++;
		parser_sphere->sp_x = ft_atof_retpos(&str);
		str++;
		parser_sphere->sp_y = ft_atof_retpos(&str);
		str++;
		parser_sphere->sp_z = ft_atof_retpos(&str);
		str++;
		parser_sphere->sp_d = ft_atof_retpos(&str);
		str++;
		parser_sphere->sp_rgb_r = ft_atof_retpos(&str);
		str++;
		parser_sphere->sp_rgb_g = ft_atof_retpos(&str);
		str++;
		parser_sphere->sp_rgb_b = ft_atof_retpos(&str);

	}
	else if (parser_sphere->sp == 0)
		return ;
	else
		ft_error_met(lineadress, "Error: Too many sp", j);
}

