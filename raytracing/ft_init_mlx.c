#include "../minirt.h"


void ft_init_mlx(t_list_minirt *resolution, void **mlx, void **mlx_win, t_data *img)
{
	*mlx = mlx_init();	
	*mlx_win = mlx_new_window(*mlx,resolution->content->parser_resolution.r_w, resolution->content->parser_resolution.r_h, "miniRT");
	img->img = mlx_new_image(*mlx,resolution->content->parser_resolution.r_w, resolution->content->parser_resolution.r_h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}
