#include "../minirt.h"

void ft_check_light(int j, t_parser_light *parser_light, char *(*lineadress)[LINES])
{
	char *str;

	str = (*lineadress)[--j - 1];
	if (parser_light->l == 1)
	{
		while (j > 1 && str[0] != 'l')	
			str = (*lineadress)[--j - 1];
		str++;
		parser_light->l_p_x = ft_atof_retpos(&str);
		str++;
		parser_light->l_p_y = ft_atof_retpos(&str);
		str++;
		parser_light->l_p_z = ft_atof_retpos(&str);
		str++;
		parser_light->l_r = ft_atof_retpos(&str);
		str++;
		parser_light->l_rgb_r = ft_atof_retpos(&str);
		str++;
		parser_light->l_rgb_g = ft_atof_retpos(&str);
		str++;
		parser_light->l_rgb_b = ft_atof_retpos(&str);
	}
	else if (parser_light->l == 0)
		return ;
	else
		ft_error_met(lineadress, "Error: Too many l", j);
}


