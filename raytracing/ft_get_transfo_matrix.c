#include "../minirt.h"


t_matrix_4by4 *ft_get_transfo_matrix(t_list_minirt *camera)
{
	int x;
	int y;
	t_matrix_4by4 *ptmatrix;

	ptmatrix = (t_matrix_4by4*)ft_calloc(1,sizeof(t_matrix_4by4));
	x = 0;
	while (x <= 3)
	{
		y = 0;
		while (y <= 3)
		{
			(*ptmatrix)[x][y] = 0;
			y++;
		}
		x++;
	}
	(*ptmatrix)[0][0] = 1;
	(*ptmatrix)[1][1] = 1;
	(*ptmatrix)[2][2] = 1;
	(*ptmatrix)[3][3] = 1;
	(*ptmatrix)[0][3] = camera->content->parser_camera.c_n_vector_x;
	(*ptmatrix)[1][3] = camera->content->parser_camera.c_n_vector_y;
	(*ptmatrix)[2][3] = camera->content->parser_camera.c_n_vector_z;
	return (ptmatrix);
}
