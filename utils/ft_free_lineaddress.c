#include "../minirt.h"

void ft_free_lineaddress(char *(*lineadress)[LINES], int j)
{
	while (--j > 0)
		free((*lineadress)[j - 1]);
}
