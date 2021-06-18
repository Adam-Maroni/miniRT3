#include "../minirt.h"

void	ft_raytracing(t_list_minirt *head)
{
	void *mlx;
	void *mlx_win;
	t_data img;
	t_parser_camera *camera;
	t_parser_camera *resolution;
	int x;
	int y;

	mlx = NULL;
	mlx_win = NULL;
	camera = ft_look_for_camera(t_list_minirt *head);
	resolution = ft_look_for_resolution(t_list_minirt *head);
	if (!camera || !resolution)
		ft_terminate_with_error("Probleme rencontre lors de raytracing", NULL, &head, &ft_del_node_lstminirt);
	ft_init_mlx(resolution, &mlx, &mlx_win, &img);
	x = -resolution.w/2;
	while (x <= resolution.w/2)
	{
		y = -resolution.h/2
			while (y <= resolution.h/2)
			{
				t_int3 point = ft_canvas_to_viewport(x,y);
				t_color color = ft_traceray(cameraPos, point,1,INFINITY);
				ft_mlx_pixel_put(data, x, y, color);
				y++
			}
		x++
	}
}
