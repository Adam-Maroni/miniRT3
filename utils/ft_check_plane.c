#include "../minirt.h"

void ft_check_plane(int j, t_parser_plane *parser_plane, char *(*lineadress)[LINES])
{
	char *str;

	str = (*lineadress)[--j - 1];
	if (parser_plane->pl == 1)
	{
		while (j > 1 && str[0] != 'c')	
			str = (*lineadress)[--j - 1];
		parser_plane->pl = ft_atof_retpos(&str);
		str++;
		parser_plane->pl_x = ft_atof_retpos(&str);
		str++;
		parser_plane->pl_y = ft_atof_retpos(&str);
		str++;
		parser_plane->pl_z = ft_atof_retpos(&str);
		str++;
		parser_plane->pl_rgb_r = ft_atof_retpos(&str);
		str++;
		parser_plane->pl_rgb_g = ft_atof_retpos(&str);
		str++;
		parser_plane->pl_rgb_b = ft_atof_retpos(&str);
		str++;
		parser_plane->pl_nvector_x = ft_atof_retpos(&str);
		str++;
		parser_plane->pl_nvector_y = ft_atof_retpos(&str);
		str++;
		parser_plane->pl_nvector_z = ft_atof_retpos(&str);
	}
	else if (parser_plane->pl == 0)
		return ;
	else
		ft_error_met(lineadress, "Error: Too many pl", j);
}




