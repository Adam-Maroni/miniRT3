#include "../minirt.h"


void ft_init_lineaddress(char *(*lineaddress)[LINES])
{
	int i;

	i = -1;
	while (++i < LINES)
		(*lineaddress)[i] = NULL;
}
