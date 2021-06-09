#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "miniLibX/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <limits.h>
# define LINES 66

typedef struct s_parser_resolution{
	int r;
	int r_w;
	int r_h;
} t_parser_resolution;

typedef struct s_parser_ambient{
	int a;
	float a_r;
	int a_rgb_r;
	int a_rgb_g;
	int a_rgb_b;
} t_parser_ambient;

typedef struct s_parser_camera{
	int c;
	float c_pov_x;
	float c_pov_y;
	float c_pov_z;
	float c_nvector_x;
	float c_nvector_y;
	float c_nvector_z;
	int c_fov;
} t_parser_camera;

typedef struct s_parser_light{
	int l;
	float l_p_x;
	float l_p_y;
	float l_p_z;
	float l_r;
	int l_rgb_r;
	int l_rgb_g;
	int l_rgb_b;
} t_parser_light;

typedef struct s_parser_sphere{
	int sp;
	float sp_x;
	float sp_y;
	float sp_z;
	float sp_d;
	int sp_rgb_r;
	int sp_rgb_g;
	int sp_rgb_b;
} t_parser_sphere;

typedef struct s_parser_plane{
	int pl;
	float pl_x;
	float pl_y;
	float pl_z;
	int pl_rgb_r;
	int pl_rgb_g;
	int pl_rgb_b;
	float pl_nvector_x;
	float pl_nvector_y;
	float pl_nvector_z;
} t_parser_plane;

typedef struct s_parser_square{
	int sq;
	float sq_x;
	float sq_y;
	float sq_z;
	float sq_nvector_x;
	float sq_nvector_y;
	float sq_nvector_z;
	float sq_sd;
	int sq_rgb_r;
	int sq_rgb_g;
	int sq_rgb_b;
} t_parser_square;

typedef struct s_parser_cylinder{
	int cy;
	float cy_x;
	float cy_y;
	float cy_z;
	float cy_nvector_x;
	float cy_nvector_y;
	float cy_nvector_z;
	float cy_d;
	float cy_h;
} t_parser_cylinder;

typedef struct s_parser_triangle{
	int tr;
	float tr_1_x;
	float tr_1_y;
	float tr_1_z;
	float tr_2_x;
	float tr_2_y;
	float tr_2_z;
	float tr_3_x;
	float tr_3_y;
	float tr_3_z;
	float tr_rgb_r;
	float tr_rgb_g;
	float tr_rgb_b;
} t_parser_triangle;

typedef struct s_parser_global{
	t_parser_resolution parser_resolution;
	t_parser_ambient parser_ambient;
	t_parser_camera parser_camera;
	t_parser_light parser_light;
	t_parser_sphere parser_sphere;
	t_parser_plane parser_plane;
	t_parser_square parser_square;
	t_parser_cylinder parser_cylinder;
	t_parser_triangle parser_triangle;
} t_parser_global;

typedef struct  s_data {
	void    *img;
	char    *addr;
	int             bits_per_pixel;
	int             line_length;
	int             endian;
}   t_data; 

typedef struct s_color{
	int alpha;
	int r;
	int g;
	int b;
}	t_color;

typedef struct s_vector{
	int x;
	int y;
	int z;
}	t_vector;






typedef struct s_list_minirt{
	t_parser_global *content;
	struct s_list_minirt *next;
} t_list_minirt;



t_list_minirt	*ft_lstlast_minirt(t_list_minirt *lst);
void			ft_lstadd_back_minirt(t_list_minirt **head, t_list_minirt *new);
void	ft_lstadd_front_minirt(t_list_minirt **alst, t_list_minirt *new);
void	ft_lstclear_minirt(t_list_minirt **lst, void (*del)(void*));
void	ft_lstdelone_minirt(t_list_minirt *lst, void (*del)(void*));
void	ft_lstiter_minirt(t_list_minirt *lst, void (*f)(void *));
t_list_minirt	*ft_lstmap_minirt(t_list_minirt *lst, void *(*f)(void *), void (*del)(void *));
t_list_minirt	*ft_lstnew_minirt(void *content);
int	ft_lstsize_minirt(t_list_minirt *lst);



void ft_init_parser_ambient(t_parser_ambient *parser_ambient);
void ft_init_parser_camera(t_parser_camera *parser_camera);
void ft_init_parser_cylinder(t_parser_cylinder *parser_cylinder);
void ft_init_parser_global(t_parser_global *parser_global);
void ft_init_parser_light(t_parser_light *parser_light);
void ft_init_parser_plane(t_parser_plane *parser_plane);
void ft_init_parser_resolution(t_parser_resolution *parser_resolution);
void ft_init_parser_sphere(t_parser_sphere *parser_sphere);
void ft_init_parser_square(t_parser_square *parser_square);
void ft_init_parser_triangle(t_parser_triangle *parser_triangle);;
#endif
