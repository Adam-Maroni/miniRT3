#include "../minirt.h"

void ft_check_cylinder(int j, t_parser_cylinder *parser_cylinder, char *(*lineadress)[LINES])
{
	char *str;

	str = (*lineadress)[--j - 1];
	if (parser_cylinder->cy == 1)
	{
		while (j > 1 && str[0] != 'c')	
			str = (*lineadress)[--j - 1];
		str++;
		parser_cylinder->cy = ft_atof_retpos(&str);
		str++;
		parser_cylinder->cy_x = ft_atof_retpos(&str);
		str++;
		parser_cylinder->cy_y = ft_atof_retpos(&str);
		str++;
		parser_cylinder->cy_z = ft_atof_retpos(&str);
		str++;
		parser_cylinder->cy_nvector_x = ft_atof_retpos(&str);
		str++;
		parser_cylinder->cy_nvector_y = ft_atof_retpos(&str);
		str++;
		parser_cylinder->cy_nvector_z = ft_atof_retpos(&str);
		str++;
		parser_cylinder->cy_d = ft_atof_retpos(&str);
		str++;
		parser_cylinder->cy_h = ft_atof_retpos(&str);
	}
	else if (parser_cylinder->cy == 0)
		return ;
	else
		ft_error_met(lineadress, "Error: Too many cy", j);
}
