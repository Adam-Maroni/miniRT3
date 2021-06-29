#include "../minirt.h"

t_float3	ft_int_times_float3(int a, t_float3 *b)
{
	t_float3	rt;	
	rt.x = b->x * a;
	rt.y = b->y * a;
	rt.z = b->z * a;
	return (rt);
}
