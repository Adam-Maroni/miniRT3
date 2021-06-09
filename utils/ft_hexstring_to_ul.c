#include "../minirt.h"

int ft_hex_to_int_table(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if ((c >= 'a') && (c <= 'f'))
		return (c - 'a' + 10);
	if ((c >= 'A') && (c <= 'F'))
		return (c - 'A' + 10);
	return (0);
}

unsigned long ft_hexstring_to_ul(char *input)
{
	int i;
	int power;
	unsigned long rt;

	i = 0;
	rt = 0;
	power = 0;
	while (input[i])
		i++;
	i--;
	while (i >= 0 && (input[i] != 'x' || input[i] != 'X'))
	{
		rt += ft_hex_to_int_table(input[i]) * pow(16,power);
		power++;
		i--;
	}
	return (rt);
}


/*
int main()
{
	char *string = "0xFF";
	printf("%lu\n", ft_hexstring_to_ul(string));
	return (0);
}
*/
