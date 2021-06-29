#include "../minirt.h"

void	ft_raytracing(t_list_minirt *head)
{
	void *mlx;
	void *mlx_win;
	t_data img;
	t_list_minirt *camera = NULL;
	t_list_minirt *resolution = NULL;
	int color;
	int x;
	int y;
	t_color *background_color = (t_color*)ft_calloc(sizeof(t_color),1);
	t_color black = {0,0,0,0};
	*background_color = black;

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
				t_float3 *direction = ft_canvas_to_viewport(x,y,camera, resolution);
				color = ft_traceray(camera, direction,1,(int)INFINITY, head, background_color);
				//Là il faut traduire x et y dans leur coordonnée axées haut gauche
				int sx = resolution->content->parser_resolution.r_w / 2 + x;
				int sy = resolution->content->parser_resolution.r_h / 2 + y;
				ft_mlx_pixel_put(&img, sx, sy, color);
				y++;
			}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}




