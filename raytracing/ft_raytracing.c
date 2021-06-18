#include "../minirt.h"

void	ft_raytracing(t_list_minirt *head)
{
	void *mlx;
	void *mlx_win;
	t_data img;
	t_list_minirt *camera = NULL;
	t_list_minirt *resolution = NULL;
	t_color *color = NULL;
	int x;
	int y;

	mlx = NULL;
	mlx_win = NULL;
	camera = ft_look_for_camera(head);
	resolution = ft_look_for_resolution(head);
	if (!camera || !resolution)
		ft_terminate_with_error("Probleme rencontre lors de raytracing", NULL, &head, &ft_del_node_lstminirt);
	ft_init_mlx(resolution, &mlx, &mlx_win, &img);
	x = -resolution->content->parser_resolution.r_w / 2;
	while (x <= resolution->content->parser_resolution.r_w / 2)
	{
		y = -resolution->content->parser_resolution.r_h / 2;
			while (y <= resolution->content->parser_resolution.r_h / 2)
			{
				t_int3 *point = ft_canvas_to_viewport(x,y,camera, resolution);
				color = ft_traceray(camera, point,1,(int)INFINITY);
				ft_mlx_pixel_put(data, x, y, color);
				y++;
			}
		x++;
	}
	free(color);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}




