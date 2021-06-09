#include "../minirt.h"

void ft_error_met(char *(*lineadress)[LINES], char *message, int j)
{
	printf("%s\n", message);
	ft_free_lineaddress(lineadress, j);
	exit(0);
}
