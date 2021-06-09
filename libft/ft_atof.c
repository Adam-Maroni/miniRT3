#include "libft.h"

float	ft_atof(char *str)
{
	int	integer;
	int	sign;
	float	decimal;

	sign = 1;
	decimal = 0;
	integer = 0;
	while (ft_isspace((int)(*str)) != 0)
		str++;
	if (ft_issign(*str) != 0)
	{
		sign = ft_issign(*str);
		str++;
	}
	integer = ft_atoi_retpos(&str);
	if (*str == '.')
	{
		str++;
		decimal = ft_atoi_retpos(&str);
		while (decimal > 1)
			decimal *= 0.1;
	}
	return ((integer + decimal) * sign);
}
