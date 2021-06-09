#include "../minirt.h"

void ft_init_parser_plane(t_parser_plane *parser_plane)
{
        parser_plane->pl = 0;
        parser_plane->pl_x = 0;
        parser_plane->pl_y = 0;
        parser_plane->pl_z = 0;
        parser_plane->pl_rgb_r = 0;
        parser_plane->pl_rgb_g = 0;
        parser_plane->pl_rgb_b = 0;
        parser_plane->pl_nvector_x = 0;
        parser_plane->pl_nvector_y = 0;
        parser_plane->pl_nvector_z = 0;
}

