#include "../minirt.h"


t_color	ft_float_times_t_color(t_color *a, float b)
{
	t_color rt;
	
	rt.r = a->r * b;
	rt.g = a->g * b;
	rt.b = a->b * b;
	return (rt);
}
