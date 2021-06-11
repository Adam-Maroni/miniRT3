#include "../minirt.h"


void ft_free_lineaddress(char *(*lineaddress)[LINES])
{
	int i;

	i = LINES;
	while (--i >= 0)
		free ((*lineaddress)[i]);
	ft_init_lineaddress(lineaddress);
}
