#include "../minirt.h"


t_matrix_4by1 *ft_canvas_to_viewport(int x, int y, t_list_minirt *camera, t_list_minirt *resolution)
{
	/*
	rt = ft_calculate_viewport(camera);
	rt->x = x * rt->x / resolution->content->parser_resolution.r_w;
	rt->y = y * rt->y / resolution->content->parser_resolution.r_h;
	rt->z = rt->z;
	*/


	//On tente de simplifier les calculs avec ca
	if (camera){;}
	t_matrix_4by1 *rt_matrix;
	rt_matrix = (t_matrix_4by1*)ft_calloc(1,sizeof(t_matrix_4by1));
	ft_init_matrix_4by1(rt_matrix);
	(*rt_matrix)[0][0] = ((float)x * 1 / resolution->content->parser_resolution.r_w);
	(*rt_matrix)[1][0] = ((float)y * 1 / resolution->content->parser_resolution.r_w); //on divise par r_w pour eviter les problemes de resolution de l'image
	//avec l'utilisation de la matrice de transfo, il était nécessaire de passer le z à 0 vu que on additionne avec c_nvector_z
	(*rt_matrix)[2][0] = 0;
	(*rt_matrix)[3][0] = 1;
	return (rt_matrix);
}
