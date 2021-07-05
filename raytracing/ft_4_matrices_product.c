#include "../minirt.h"

t_matrix_4by1 *ft_4_matrices_product(t_matrix_4by4 *matrix1, t_matrix_4by1 *matrix2)
{
	int i;
	int j;
	int k;
	t_matrix_4by1 *rt_matrix;

	rt_matrix = (t_matrix_4by1*)ft_calloc(1, sizeof(t_matrix_4by1));
	ft_init_matrix_4by1(rt_matrix);
	i = 0;
	while (i <= 3)
	{
		j = 0;
		k = 0;
		while (k <= 3)
		{
			(*rt_matrix)[i][j] += (*matrix1)[i][k] * (*matrix2)[k][j];
			k++;
		}
		i++;
	}
	return (rt_matrix);
}
