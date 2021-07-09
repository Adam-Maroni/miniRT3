#include "../minirt.h"




int ft_is_line_empty(char *line)
{

	if (!ft_strncmp(line, "\n", ft_strlen(line)))
		return (1);
	return (0);
}
