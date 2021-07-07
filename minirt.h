#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>
# include "miniLibX/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
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
	float c_n_vector_x;
	float c_n_vector_y;
	float c_n_vector_z;
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
	float pl_n_vector_x;
	float pl_n_vector_y;
	float pl_n_vector_z;
} t_parser_plane;

typedef struct s_parser_square{
	int sq;
	float sq_x;
	float sq_y;
	float sq_z;
	float sq_n_vector_x;
	float sq_n_vector_y;
	float sq_n_vector_z;
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
	float cy_n_vector_x;
	float cy_n_vector_y;
	float cy_n_vector_z;
	float cy_d;
	float cy_h;
	int	cy_rgb_r;
	int	cy_rgb_g;
	int	cy_rgb_b;
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

typedef struct s_float3{
	float x;
	float y;
	float z;
}	t_float3;

typedef struct s_float2{
	float t1;
	float t2;
}	t_float2;






typedef struct s_list_minirt{
	t_parser_global *content;
	struct s_list_minirt *next;
} t_list_minirt;


typedef char (*t_lineaddress)[LINES];

t_list_minirt	*ft_lstlast_minirt(t_list_minirt *lst);
void			ft_lstadd_back_minirt(t_list_minirt **alst, t_list_minirt *new);
void	ft_lstadd_front_minirt(t_list_minirt **alst, t_list_minirt *new);
void	ft_lstclear_minirt(t_list_minirt **lst, void (*del)(void*));
void	ft_lstdelone_minirt(t_list_minirt *lst, void (*del)(void*));
void	ft_lstiter_minirt(t_list_minirt *lst, void (*f)(void *));
t_list_minirt	*ft_lstmap_minirt(t_list_minirt *lst, void *(*f)(void *), void (*del)(void *));
t_list_minirt	*ft_lstnew_minirt(void *content);
int	ft_lstsize_minirt(t_list_minirt *lst);
void ft_del_node_lstminirt(void *content);



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
void ft_error_met(char *message);
void ft_error_met(char *message);
void ft_init_lineaddress(char *(*lineaddress)[LINES]);
void ft_free_lineaddress(char *(*lineaddress)[LINES]);
int ft_check_resolution(char *line);
int ft_check_ambient(char *line);
int ft_check_camera(char *line);
void ft_terminate_with_error(char *message, char *(*lineaddress)[66], t_list_minirt **head, void (*ft_del_node_lstminirt));
int ft_check_light(char *line);
int ft_check_plane(char *line);
int ft_check_sphere(char *line);
int ft_check_cylinder(char *line);
t_parser_global *ft_parse_resolution(char *line);
t_parser_global *ft_parse_ambient(char *line);
t_parser_global *ft_parse_camera(char *line);
t_parser_global *ft_parse_light(char *line);
t_parser_global *ft_parse_plane(char *line);
t_parser_global *ft_parse_sphere(char *line);
t_parser_global *ft_parse_cylinder(char *line);
t_parser_global *ft_parse_line(char *line, int parse_choice);
int ft_check_for_duplicate_resolution(t_list_minirt *head);
int ft_check_for_duplicate_ambient(t_list_minirt *head);
int ft_check_for_duplicate_camera(t_list_minirt *head);
int ft_check_for_duplicate_light(t_list_minirt *head);
int ft_check_for_duplicate(t_list_minirt **head);
int ft_check_for_mandatory_resolution(t_list_minirt *head);
int ft_check_for_mandatory_ambient(t_list_minirt *head);
int ft_check_for_mandatory_camera(t_list_minirt *head);
int ft_check_for_mandatory_light(t_list_minirt *head);
int ft_check_for_mandatory(t_list_minirt **head);


t_float3 *ft_calculate_viewport(t_list_minirt *camera);
float ft_closest_intersection(t_float3 origin, t_float3 direction, float tmin, float tmax, t_list_minirt *head, t_list_minirt **closest_sphere);
float ft_compute_lighting(t_float3 p, t_float3 n, t_list_minirt *head,  float tmin, float tmax);
float	ft_deg_to_rad(int deg);
float    ft_dot_product(t_float3 a, t_float3 b);
t_list_minirt *ft_find_next_ambient(t_list_minirt *previous_light, t_list_minirt *head);
t_list_minirt *ft_find_next_light(t_list_minirt *previous_light, t_list_minirt *head);
t_list_minirt *ft_find_next_sphere(t_list_minirt *previous_sphere, t_list_minirt *head);
t_float3 ft_float3_minus_float3(t_float3 a, t_float3 b);
t_float3 ft_float3_plus_float3(t_float3 a, t_float3 b);
t_color	ft_float_times_t_color(t_color *a, float b);
t_float3 ft_get_camera_position(t_list_minirt *camera);
t_float3 ft_get_light_position(t_list_minirt *light);
float ft_get_norm(t_float3 i);
t_float3 ft_get_sphere_center(t_list_minirt *sphere);
t_color *ft_get_sphere_color(t_list_minirt *sphere);
int ft_hex_to_int_table(char c);
unsigned long ft_hexstring_to_ul(char *input);
void ft_init_mlx(t_list_minirt *resolution, void **mlx, void **mlx_win, t_data *img);
t_float2 *ft_intersect_ray_with_sphere(t_float3 origin, t_float3 direction, t_float3 sphere, t_list_minirt *spherelst);
t_float3	ft_float_times_float3(float a, t_float3 b);
t_list_minirt	*ft_look_for_camera(t_list_minirt *lst);
t_list_minirt *ft_look_for_resolution(t_list_minirt *lst);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_raytracing(t_list_minirt *head);
int	ft_rt_min_max(int min, int max, int input);
float ft_square(float i);
unsigned long ft_t_color_to_ul(t_color *input);
int ft_traceray(t_list_minirt *camera, t_float3 direction, float tmin, float tmax, t_list_minirt *head, t_color *background_color);
char	conversion_hex_table(unsigned long input, char c);
char	*int2hexstring(unsigned long input, char c, size_t size);
t_float3 ft_get_camera_orientation(t_list_minirt *camera);
t_float3 ft_float3_times_float3(t_float3 a, t_float3 b);





typedef float (t_matrix_4by1)[4][1];
typedef float (t_matrix_4by4)[4][4];
t_matrix_4by4 *ft_get_transfo_matrix(t_list_minirt *camera);
t_matrix_4by1 *ft_canvas_to_viewport(int x, int y, t_list_minirt *camera, t_list_minirt *resolution);
t_matrix_4by1 *ft_4_matrices_product(t_matrix_4by4 *matrix1, t_matrix_4by1 *matrix2);
void ft_init_matrix_4by1(t_matrix_4by1 *matrix);
t_float3 ft_matrix4by1_to_float3(t_matrix_4by1 *matrix);

int ft_is_a_shape(t_list_minirt *lst);
int ft_is_a_sphere(t_list_minirt *lst);
int ft_is_a_plane(t_list_minirt *lst);
int ft_is_a_cylinder(t_list_minirt *lst);
t_list_minirt *ft_find_next_shape(t_list_minirt *previous_shape, t_list_minirt *head);
t_float3 ft_get_shape_center(t_list_minirt *shape);
t_color *ft_get_shape_color(t_list_minirt *shape);
#endif




