#include "../minirt.h"


int	ft_rt_min_max(int min, int max, int input)
{
	if (input > max)
		return (max);
	if (input < min)
		return (min);
	else
		return (input);
}
