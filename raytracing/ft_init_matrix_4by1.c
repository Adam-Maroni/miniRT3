#include "../minirt.h"

void ft_init_matrix_4by1(t_pt_matrix_4by1 matrix)
{
	int i;

	i = 0;
	while (i <= 3)
	{
		*matrix[i][0] = 0;
		i++;
	}
}
