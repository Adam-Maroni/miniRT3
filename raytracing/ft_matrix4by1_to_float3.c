#include "../minirt.h"


t_float3 ft_matrix4by1_to_float3(t_pt_matrix_4by1 matrix)
{
	t_float3 rt;
	
	rt.x = *matrix[0][0];
	rt.y = *matrix[1][1];
	rt.z = *matrix[2][2];
	return (rt);
}
