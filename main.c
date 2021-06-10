#include "minirt.h"

typedef char (*t_lineaddress)[LINES];


void ft_error_met(char *message)
{
	printf("%s\n", message);
	exit (0);
}


void ft_init_lineaddress(char *(*lineaddress)[LINES])
{
	int i;

	i = -1;
	while (++i < LINES)
		(*lineaddress)[i] = NULL;
}

void ft_free_lineaddress(char *(*lineaddress)[LINES])
{
	int i;

	i = LINES;
	while (--i >= 0)
		free ((*lineaddress)[i]);
	ft_init_lineaddress(lineaddress);
}

int ft_check_resolution(char *line)
{
	int width;
	int height;

	width = 0;
	height = 0;
	if (line[0] == 'R' && ft_isspace((int)(line[1])))
	{
		line++;
		width = ft_atoi_retpos(&line);
		height = ft_atoi_retpos(&line);
		if (width <= 0 || height <= 0)
			return (0);
		return (1);
	}
	return (0);
}

t_parser_global ft_parse_resolution(char *line)
{
	t_parser_global content;

	int width;
	int height;


	ft_init_parser_global(&content);
	line++;
	width = ft_atoi_retpos(&line);
	height = ft_atoi_retpos(&line);
	content.parser_resolution.r = 1;
	content.parser_resolution.r_w = width;
	content.parser_resolution.r_h = height;
	return (content);
}

int ft_check_ambient(char *line)
{

	t_parser_global content;
	if (line[0] == 'A' && ft_isspace((int)(line[1])))
	{
		line++;
		content.parser_ambient.a_r = ft_atof_retpos(&line);
		line++;
		content.parser_ambient.a_rgb_r = ft_atoi_retpos(&line);
		line++;
		content.parser_ambient.a_rgb_g = ft_atoi_retpos(&line);
		line++;
		content.parser_ambient.a_rgb_b = ft_atoi_retpos(&line);

		if ((content.parser_ambient.a_r < 0 || content.parser_ambient.a_r > 1)
		|| (content.parser_ambient.a_rgb_r < 0 || content.parser_ambient.a_rgb_r > 255)
		|| (content.parser_ambient.a_rgb_g < 0 || content.parser_ambient.a_rgb_g > 255)
		|| (content.parser_ambient.a_rgb_b < 0 || content.parser_ambient.a_rgb_b > 255))
			return (0);
		return (1)
	}
	return (0);
}

t_parser_global *ft_parse_ambient(char *line)
{

	t_parser_global content;
	
	ft_init_parser_global(&content);
	content.parser_ambient.a = 1;
	line++;
	content.parser_ambient.a_r = ft_atof_retpos(&line);
	line++;
	content.parser_ambient.a_rgb_r = ft_atoi_retpos(&line);
	line++;
	content.parser_ambient.a_rgb_g = ft_atoi_retpos(&line);
	line++;
	content.parser_ambient.a_rgb_b = ft_atoi_retpos(&line);
	return (content);
}

int ft_check_camera(char *line)
{

	t_parser_global content;
	if (line[0] == 'C' && ft_isspace((int)(line[1])))
	{
		line++;
		content.parser_camera.c_pov_x = ft_atof_retpos(&line);
		line++;
		content.parser_camera.c_pov_y = ft_atof_retpos(&line);
		line++;
		content.parser_camera.c_pov_z = ft_atof_retpos(&line);
		line++;
		content.parser_camera.c_n_vector_x = ft_atof_retpos(&line);
		line++;
		content.parser_camera.c_n_vector_y = ft_atof_retpos(&line);
		line++;
		content.parser_camera.c_n_vector_z = ft_atof_retpos(&line);
		line++;
		content.parser_camera.fov = ft_atoi_retpos(&line);
		if ((content.parser_camera.c_n_vector_x < -1 || content.parser_camera.c_n_vector_x > 1)
		|| (content.parser_camera.c_nvector_y < -1 || content.parser_camera.c_n_vector_y > 1)
		|| (content.parser_camera.c_n_vector_z < -1 || content.parser_camera.c_n_vector_z > 1)
		|| (content.parser_camera.fov < 0 || content.parser_camera.fov > 180));
			return (0);
		return (1)
	}
	return (0);
}

t_parser_global *ft_parse_camera(char *line)
{

	t_parser_global content;
	
	content.parser_camera.c = 1;
	line++;
	content.parser_camera.c_pov_x = ft_atof_retpos(&line);
	line++;
	content.parser_camera.c_pov_y = ft_atof_retpos(&line);
	line++;
	content.parser_camera.c_pov_z = ft_atof_retpos(&line);
	line++;
	content.parser_camera.c_n_vector_x = ft_atof_retpos(&line);
	line++;
	content.parser_camera.c_n_vector_y = ft_atof_retpos(&line);
	line++;
	content.parser_camera.c_n_vector_z = ft_atof_retpos(&line);
	line++;
	content.parser_camera.fov = ft_atoi_retpos(&line);
	return (content);
}


int ft_is_line_correct(char *line)
{
	if (ft_check_resolution(line))
		return (1);
	if (ft_check_ambient(line))
		return (2);
	if (ft_check_camera(line))
		return (3);
	if (ft_check_cylinder(line))
		return (4);
	if (ft_check_light(line))
		return (5);
	if (ft_check_plane(line))
		return (6);
	if (ft_check_sphere(line))
		return (7);
	return (0);
}

t_parser_global *ft_parse_line(char *line, int parse_choice)
{
	t_parser_global *content;

	content = NULL;
	if (parse_choice == 1)
		content = ft_parse_resolution(*line);
	if (parse_choice == 2)
		content = ft_parse_ambient(*line);
	if (parse_choice == 3)
		content = ft_parse_camera(*line);
	if (parse_choice == 4)
		content = ft_parse_cylinder(*line);
	if (parse_choice == 5)
		content = ft_parse_light(*line);
	if (parse_choice == 6)
		content = ft_parse_plane(*line);
	if (parse_choice == 7)
		content = ft_parse_sphere(*line);
	return (content);
}

/*
void	ft_check_line(char *line, t_parser_global *content)
{
	if (ft_check_resolution(line))
		*content = ft_parsing_resolution(line);
	else if (ft_check_resolution(line) < 0)
		ft_error_met("Resolution invalide."); //+LIBERER LA MEMOIRE
	//else if (line[0] == 'A' && ft_isspace((int)(line[1])))
	//else if (line[0] == 'c' && ft_isspace((int)(line[1])))
	//else if (line[0] == 'l' && ft_isspace((int)(line[1])))
	//else if (line[0] == 'p' && line[1] == 'l' && ft_isspace((int)(line[2])))
	//else if (line[0] == 's' && line[1] == 'p' && ft_isspace((int)(line[2])))
	//else if (line[0] == 's' && line[1] == 'q' && ft_isspace((int)(line[2])))
	//else if (line[0] == 'c' && line[1] == 'y' && ft_isspace((int)(line[2])))
	//else if (line[0] == 't' && line[1] == 'r' && ft_isspace((int)(line[2])))
	else
		content = NULL;
}
*/

void ft_terminate_with_error(char *message, t_lineaddress *lineaddress, t_list_minirt **head, void (*ft_del_node_lstminirt)(void*))
{
	if (lineaddress)
		ft_free_lineaddress(lineaddress);
	if (head)
		ft_lstclear_minirt(head, &ft_del_node_lstminirt);
	ft_error_met(message);
}




int ft_check_light(char *line)
{

	t_parser_global content;
	if (line[0] == 'L' && ft_isspace((int)(line[1])))
	{
		line++;
		content.parser_light.l_p_x = ft_atof_retpos(&line);
		line++;
		content.parser_light.l_p_y = ft_atof_retpos(&line);
		line++;
		content.parser_light.l_p_z = ft_atof_retpos(&line);
		line++;
		content.parser_light.l_p_r = ft_atof_retpos(&line);
		line++;
		content.parser_light.l_rgb_r = ft_atoi_retpos(&line);
		line++;
		content.parser_light.l_rgb_g = ft_atoi_retpos(&line);
		line++;
		content.parser_light.l_rgb_b = ft_atoi_retpos(&line);
		if ((content.parser_light.l_r < 0 || content.parser_light.l_r > 1)
		|| (content.parser_light.l_rgb_r < 0 || content.parser_light.l_rgb_r > 255)
		|| (content.parser_light.l_rgb_g < 0 || content.parser_light.l_rgb_g > 255)
		|| (content.parser_light.l_rgb_b < 0 || content.parser_light.l_rgb_b > 255))
			return (0);
		return (1)
	}
	return (0);
}


t_parser_global *ft_parse_light(char *line)
{

	t_parser_global content;
	
	content.parser_light.l = 1;
	line++;
	content.parser_light.l_p_x = ft_atof_retpos(&line);
	line++;
	content.parser_light.l_p_y = ft_atof_retpos(&line);
	line++;
	content.parser_light.l_p_z = ft_atof_retpos(&line);
	line++;
	content.parser_light.l_p_r = ft_atof_retpos(&line);
	line++;
	content.parser_light.l_rgb_r = ft_atoi_retpos(&line);
	line++;
	content.parser_light.l_rgb_g = ft_atoi_retpos(&line);
	line++;
	content.parser_light.l_rgb_b = ft_atoi_retpos(&line);
	return (content);
}

int ft_check_plane(char *line)
{

	t_parser_global content;
	if (line[0] == 'p' && line[1] == 'l' && ft_isspace((int)(line[2])))
	{
		line++;
		content.parser_plane.pl_x = ft_atof_retpos(&line);
		line++;
		content.parser_plane.pl_y = ft_atof_retpos(&line);
		line++;
		content.parser_plane.pl_z = ft_atof_retpos(&line);
		line++;
		content.parser_plane.pl_rgb_r = ft_atoi_retpos(&line);
		line++;
		content.parser_plane.pl_rgb_g = ft_atoi_retpos(&line);
		line++;
		content.parser_plane.pl_rgb_b = ft_atoi_retpos(&line);
		line++;
		content.parser_plane.pl_nvector_x = ft_atof_retpos(&line);
		line++;
		content.parser_plane.pl_nvector_y = ft_atof_retpos(&line);
		line++;
		content.parser_plane.pl_nvector_z = ft_atof_retpos(&line);

		if ((content.parser_plane.l_r < 0 || content.parser_plane.l_r > 1)
		|| (content.parser_plane.pl_rgb_r < 0 || content.parser_plane.pl_rgb_r > 255)
		|| (content.parser_plane.pl_rgb_g < 0 || content.parser_plane.pl_rgb_g > 255)
		|| (content.parser_plane.pl_rgb_b < 0 || content.parser_plane.pl_rgb_b > 255))
		|| (content.parser_plane.pl_n_vector_x < -1 || content.parser_plane.pl_n_vector_x > 1)
		|| (content.parser_plane.pl_n_vector_y < -1 || content.parser_plane.pl_n_vector_y > 1)
		|| (content.parser_plane.pl_n_vector_z < -1 || content.parser_plane.pl_n_vector_z > 1)
			return (0);
		return (1)
	}
	return (0);
}


t_parser_global *ft_parse_plane(char *line)
{

	t_parser_global content;
	
	content.parser_plane.pl = 1;
	line++;
	content.parser_plane.pl_x = ft_atof_retpos(&line);
	line++;
	content.parser_plane.pl_y = ft_atof_retpos(&line);
	line++;
	content.parser_plane.pl_z = ft_atof_retpos(&line);
	line++;
	content.parser_plane.pl_rgb_r = ft_atoi_retpos(&line);
	line++;
	content.parser_plane.pl_rgb_g = ft_atoi_retpos(&line);
	line++;
	content.parser_plane.pl_rgb_b = ft_atoi_retpos(&line);
	line++;
	content.parser_plane.pl_nvector_x = ft_atof_retpos(&line);
	line++;
	content.parser_plane.pl_nvector_y = ft_atof_retpos(&line);
	line++;
	content.parser_plane.pl_nvector_z = ft_atof_retpos(&line);
	return (content);
}











































int ft_check_sphere(char *line)
{

	t_parser_global content;
	if (line[0] == 's' && line[1] == 'p' && ft_isspace((int)(line[2])))
	{
		line++;
		content.parser_sphere.sp_x = ft_atof_retpos(&line);
		line++;
		content.parser_sphere.sp_y = ft_atof_retpos(&line);
		line++;
		content.parser_sphere.sp_z = ft_atof_retpos(&line);
		line++;
		content.parser_sphere.sp_d = ft_atof_retpos(&line);
		line++;
		content.parser_sphere.sp_rgb_r = ft_atoi_retpos(&line);
		line++;
		content.parser_sphere.sp_rgb_g = ft_atoi_retpos(&line);
		line++;
		content.parser_sphere.sp_rgb_b = ft_atoi_retpos(&line);

		if ((content.parser_sphere.sp_rgb_r < 0 || content.parser_sphere.sp_rgb_r > 255)
		|| (content.parser_sphere.sp_rgb_g < 0 || content.parser_sphere.sp_rgb_g > 255)
		|| (content.parser_sphere.sp_rgb_b < 0 || content.parser_sphere.sp_rgb_b > 255))
			return (0);
		return (1)
	}
	return (0);
}


t_parser_global *ft_parse_sphere(char *line)
{

	t_parser_global content;
	
	content.parser_sphere.sp = 1;
	line++;
	content.parser_sphere.sp_x = ft_atof_retpos(&line);
	line++;
	content.parser_sphere.sp_y = ft_atof_retpos(&line);
	line++;
	content.parser_sphere.sp_z = ft_atof_retpos(&line);
	line++;
	content.parser_sphere.sp_d = ft_atof_retpos(&line);
	line++;
	content.parser_sphere.sp_rgb_r = ft_atoi_retpos(&line);
	line++;
	content.parser_sphere.sp_rgb_g = ft_atoi_retpos(&line);
	line++;
	content.parser_sphere.sp_rgb_b = ft_atoi_retpos(&line);
	return (content);
}






int ft_check_square(char *line)
{

	t_parser_global content;
	if (line[0] == 'p' && line[1] == 'l' && ft_isspace((int)(line[2])))
	{
		line++;

int ft_check_cylinder(char *line)
{

	t_parser_global content;
	if (line[0] == 'c' && line[1] == 'y' && ft_isspace((int)(line[2])))
	{
		line++;
		content.parser_cylinder.cy_x = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_y = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_z = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_nvector_x = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_nvector_y = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_nvector_z = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_d = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_h = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_rgb_r = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_rgb_g = ft_atof_retpos(&line);
		line++;
		content.parser_cylinder.cy_rgb_b = ft_atof_retpos(&line);

		if ((content.parser_cylinder.cy_rgb_r < 0 || content.parser_cylinder.cy_rgb_r > 255)
		|| (content.parser_cylinder.cy_rgb_g < 0 || content.parser_cylinder.cy_rgb_g > 255)
		|| (content.parser_cylinder.cy_rgb_b < 0 || content.parser_cylinder.cy_rgb_b > 255)
		|| (content.parser_cylinder.cy_n_vector_x < -1 || content.parser_cylinder.cy_n_vector_x > 1)
		|| (content.parser_cylinder.cy_n_vector_y < -1 || content.parser_cylinder.cy_n_vector_y > 1)
		|| (content.parser_cylinder.cy_n_vector_z < -1 || content.parser_cylinder.cy_n_vector_z > 1))
			return (0);
		return (1)
	}
	return (0);
}


t_parser_global *ft_parse_cylinder(char *line)
{

	t_parser_global content;

	content.parser_cylinder.cy = 1;
	line++;
	content.parser_cylinder.cy_x = ft_atof_retpos(&line);
	line++;
	content.parser_cylinder.cy_y = ft_atof_retpos(&line);
	line++;
	content.parser_cylinder.cy_z = ft_atof_retpos(&line);
	line++;
	content.parser_cylinder.cy_nvector_x = ft_atof_retpos(&line);
	line++;
	content.parser_cylinder.cy_nvector_y = ft_atof_retpos(&line);
	line++;
	content.parser_cylinder.cy_nvector_z = ft_atof_retpos(&line);
	line++;
	content.parser_cylinder.cy_d = ft_atof_retpos(&line);
	line++;
	content.parser_cylinder.cy_h = ft_atof_retpos(&line);
	line++;
	content.parser_cylinder.cy_rgb_r = ft_atof_retpos(&line);
	line++;
	content.parser_cylinder.cy_rgb_g = ft_atof_retpos(&line);
	line++;
	content.parser_cylinder.cy_rgb_b = ft_atof_retpos(&line);
	return (content);
}

int ft_check_triangle(char *line)
{

	t_parser_global content;
	if (line[0] == 'p' && line[1] == 'l' && ft_isspace((int)(line[2])))
	{
		line++;
		content.parser_triangle.pl_x = ft_atof_retpos(&line);
		line++;
		content.parser_triangle.pl_y = ft_atof_retpos(&line);
		line++;
		content.parser_triangle.pl_z = ft_atof_retpos(&line);
		line++;
		content.parser_triangle.pl_rgb_r = ft_atoi_retpos(&line);
		line++;
		content.parser_triangle.pl_rgb_g = ft_atoi_retpos(&line);
		line++;
		content.parser_triangle.pl_rgb_b = ft_atoi_retpos(&line);
		line++;
		content.parser_triangle.pl_nvector_x = ft_atof_retpos(&line);
		line++;
		content.parser_triangle.pl_nvector_y = ft_atof_retpos(&line);
		line++;
		content.parser_triangle.pl_nvector_z = ft_atof_retpos(&line);

		if ((content.parser_triangle.l_r < 0 || content.parser_triangle.l_r > 1)
				|| (content.parser_triangle.pl_rgb_r < 0 || content.parser_triangle.pl_rgb_r > 255)
				|| (content.parser_triangle.pl_rgb_g < 0 || content.parser_triangle.pl_rgb_g > 255)
				|| (content.parser_triangle.pl_rgb_b < 0 || content.parser_triangle.pl_rgb_b > 255))
			|| (content.parser_triangle.pl_n_vector_x < -1 || content.parser_triangle.pl_n_vector_x > 1)
				|| (content.parser_triangle.pl_n_vector_y < -1 || content.parser_triangle.pl_n_vector_y > 1)
				|| (content.parser_triangle.pl_n_vector_z < -1 || content.parser_triangle.pl_n_vector_z > 1)
				return (0);
		return (1)
	}
	return (0);
}


t_parser_global *ft_parse_triangle(char *line)
{

	t_parser_global content;

	content.parser_triangle.pl = 1;
	line++;
	content.parser_triangle.pl_x = ft_atof_retpos(&line);
	line++;
	content.parser_triangle.pl_y = ft_atof_retpos(&line);
	line++;
	content.parser_triangle.pl_z = ft_atof_retpos(&line);
	line++;
	content.parser_triangle.pl_rgb_r = ft_atoi_retpos(&line);
	line++;
	content.parser_triangle.pl_rgb_g = ft_atoi_retpos(&line);
	line++;
	content.parser_triangle.pl_rgb_b = ft_atoi_retpos(&line);
	line++;
	content.parser_triangle.pl_nvector_x = ft_atof_retpos(&line);
	line++;
	content.parser_triangle.pl_nvector_y = ft_atof_retpos(&line);
	line++;
	content.parser_triangle.pl_nvector_z = ft_atof_retpos(&line);
	return (content);
}










t_list_minirt *ft_parsing(char *filepath)
{
	char *lineaddress[LINES];
	int	j;
	int fd;
	t_list_minirt *head;
	t_parser_global *parser;

	j = 0;
	head = NULL;
	parser = NULL;
	ft_init_lineaddress(&lineaddress);
	if (!(fd = open(filepath, O_RDONLY)))
		ft_terminate_with_error("Le fichier n'existe pas ou n'est pas lisible.", NULL, NULL, NULL);
	while (get_next_line(fd, &lineaddress[j]))
	{
		if (ft_is_line_correct(lineaddress[j]))
			parser = ft_parse_line(lineaddress[j], ft_is_line_correct(lineaddress[j]));
		else
			ft_terminate_with_error("Fichier invalide.",&lineaddress,head,&ft_del_node_lstminirt);
		ft_lstadd_back_minirt(&head,ft_lstnew_minirt(parser));
		j++;
	}
	close(fd);
	ft_free_lineaddress(&lineaddress);
	return (head);
}


int main(int argc, char **argv)
{
	t_list_minirt *head = NULL;
	if (argc != 2)
		ft_terminate_with_error("Trop d'argument passe en parametre", NULL, NULL, NULL);
	head = ft_parsing(argv[1]);
	ft_lstclear_minirt(&head, &ft_del_node_lstminirt);
	return (0);
}








