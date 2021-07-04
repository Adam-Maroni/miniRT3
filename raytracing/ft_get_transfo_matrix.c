#include "../minirt.h"


t_pt_matrix_4by4 ft_get_transfo_matrix(t_list_minirt *camera)
{
	t_pt_matrix_4by4 ptmatrix;
	float matrix[4][4];
	int x;
	int y;

	ptmatrix = (t_pt_matrix_4by4)ft_calloc(sizeof(*t_pt_matrix_4by4));
	x = 0;
	while (x <= 3)
	{
		y = 0;
		while (y <= 3)
		{
			matrix[x][y] = 0;
			y++;
		}
		x++;
	}
	matrix[0][0] = camera->content->parser_camera.c_n_vector_x;
	matrix[1][1] = camera->content->parser_camera.c_n_vector_y;
	matrix[2][2] = camera->content->parser_camera.c_n_vector_z;
	matrix[3][3] = 1;
	ptmatrix = &matrix;
	return (ptmatrix);
}
