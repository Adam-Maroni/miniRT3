#include "../minirt.h"

void ft_init_t_data(t_data *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

void ft_generate_image(t_parser_global *parser_global)
{
	void *mlx;
	void *mlx_win;
	
	t_data img;
	ft_init_t_data(&img);
	int width = parser_global->parser_resolution.r_w;
	int height = parser_global->parser_resolution.r_h;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "miniRT");
	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

t_vector ft_canvas_to_viewport(t_parser_global *parser, int cx, int cy)
{
	int vh;
	int vw;
	t_vector	viewport_square;

	vw = 2 * parser->parser_camera.c_pov_z * tan(parser->parser_camera.c_fov / 2);
	vh = vw;
	viewport_square.x = cx * (vw / parser->parser_resolution.r_w);
	viewport_square.y = cy * (vh / parser->parser_resolution.r_h);
	viewport_square.z = parser->parser_camera.c_pov_z;
	return (viewport_square);
}

/*
void ft_draw_scene(t_parser_global *parser, t_data *img, int width, int height)
{
	t_vector viewport_square;
	int cx;
	int cy;

	cx = -(width)/2;
	cy = -(height)/2;
	while (cx <= width/2)
	{
		while (cy <= height/2)
		{
			viewport_square = ft_canvas_to_viewport(parser, cx, cy);
			color = trace_ray(camera, viewport_square, 1, INT_MAX):
			my_mlx_pixel_put(img, cx, cy, color);
			cy++;
		}
		cx++;
	}

}
*/
