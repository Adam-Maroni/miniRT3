#include "../minirt.h"


t_pt_matrix_4by1 ft_canvas_to_viewport(int x, int y, t_list_minirt *camera, t_list_minirt *resolution)
{
	t_pt_matrix_4by1 rt_matrix;
	/*
	rt = ft_calculate_viewport(camera);
	rt->x = x * rt->x / resolution->content->parser_resolution.r_w;
	rt->y = y * rt->y / resolution->content->parser_resolution.r_h;
	rt->z = rt->z;
	*/


	//On tente de simplifier les calculs avec ca
	if (camera){;}
	rt_matrix = (t_pt_matrix_4by1)ft_calloc(1,sizeof(*t_pt_matrix_4by1));
	ft_init_matrix_4by1(rt_matrix);
	*rt_matrix[0][0] = ((float)x * 1 / resolution->content->parser_resolution.r_w);
	*rt_matrix[1][1] = ((float)y * 1 / resolution->content->parser_resolution.r_w); //on divise par r_w pour eviter les problemes de resolution de l'image
	*rt_matrix[2][2] = 1;
	*rt_matrix[3][3] = 1;
	return (rt_matrix);
}
