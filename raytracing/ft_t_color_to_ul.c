#include "../minirt.h"

unsigned long ft_t_color_to_ul(t_color *input)
{
	unsigned long rt;
	char *tab;
	char *alpha;
	char *red;
	char *green;
	char *blue;

	//0x + 8 + /0
	tab = (char*)ft_calloc(11,sizeof(char));
	alpha = int2hexstring((unsigned long)ft_rt_min_max(0,255,input->alpha),'x',2);
	red = int2hexstring((unsigned long)ft_rt_min_max(0,255,input->r),'x',2);
	green = int2hexstring((unsigned long)ft_rt_min_max(0,255,input->g),'x',2);
	blue = int2hexstring((unsigned long)ft_rt_min_max(0,255,input->b),'x',2);
	if (ft_strncmp(alpha, "0", ft_strlen(alpha)) == 0)
		ft_strlcat(tab,"00",ft_strlen(tab)+3);
	else
		ft_strlcat(tab,alpha,ft_strlen(tab)+3);
	if (ft_strncmp(red, "0", ft_strlen(red)) == 0)
		ft_strlcat(tab,"00",ft_strlen(tab)+3);
	else
		ft_strlcat(tab,red,ft_strlen(tab)+3);
	if (ft_strncmp(green, "0", ft_strlen(green)) == 0)
		ft_strlcat(tab,"00",ft_strlen(tab)+3);
	else
		ft_strlcat(tab,green,ft_strlen(tab)+3);
	if (ft_strncmp(blue, "0", ft_strlen(blue)) == 0)
		ft_strlcat(tab,"00",ft_strlen(tab)+3);
	else
		ft_strlcat(tab,blue,ft_strlen(tab)+3);
	free(alpha);
	free(red);	
	free(green);	
	free(blue);	
	rt = ft_hexstring_to_ul(tab);
	free(tab);
	return (rt);
}
