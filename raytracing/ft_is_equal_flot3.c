#include "../minirt.h"


int ft_is_equal_float3(t_float3 a, t_float3 b)
{
	if (a.x == b.x && a.y == b.y && a.z == b.z)
		return (1);
	return (0);
}
