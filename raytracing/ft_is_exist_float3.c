#include "../minirt.h"

int ft_is_exist_float3(t_float3 a)
{
	if (a.x < (float)INFINITY && a.y < (float)INFINITY && a.z < (float)INFINITY)
		return (1);
	return (0);
}
