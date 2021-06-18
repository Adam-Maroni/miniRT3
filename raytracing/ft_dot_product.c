#include "../minirt.h"


int    ft_dot_product(t_int3 *a, t_int3 *b)
{
 return (a->x * b->x + a->y * b->y + a->z * b->z);
}

