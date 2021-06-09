#include "../minirt.h"

void ft_check_camera(int j, t_parser_camera *parser_camera, char *(*lineadress)[LINES])
{
	char *str;

	str = (*lineadress)[--j - 1];
	if (parser_camera->c == 1)
	{
		while (j > 1 && str[0] != 'c')	
			str = (*lineadress)[--j - 1];
		str++;
		parser_camera->c_pov_x = ft_atof_retpos(&str);
		str++;
		parser_camera->c_pov_y = ft_atof_retpos(&str);
		str++;
		parser_camera->c_pov_z = ft_atof_retpos(&str);
		str++;
		parser_camera->c_nvector_x = ft_atof_retpos(&str);
		str++;
		parser_camera->c_nvector_y = ft_atof_retpos(&str);
		str++;
		parser_camera->c_nvector_z = ft_atof_retpos(&str);
		str++;
		parser_camera->c_fov = ft_atoi_retpos(&str);

	}
	else if (parser_camera->c == 0)
		return ;
	else
		ft_error_met(lineadress, "Error: Too many c", j);
}




