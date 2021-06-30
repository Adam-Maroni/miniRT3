#include "../minirt.h"

t_float3 ft_float3_minus_float3(t_float3 a, t_float3 b)
{
	t_float3 rt;
	
	rt.x = a.x - b.x;
	rt.y = a.y - b.y;
	rt.z = a.z - b.z;
	return (rt);
}
