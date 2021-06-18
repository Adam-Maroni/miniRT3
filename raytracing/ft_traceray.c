#include "../minirt.h"

METHOD ft_traceray(t_parser_camera *camera, t_int3 *point, int tmin, int tmax, t_list_minirt *head)
	t_parser_sphere *closest_sphere = NULL;
	int closest_t = INFINITY
	t_int2 *solutions;
	t_list_minirt *current_sphere = NULL;

	WHILE ((current_sphere = ft_find_next_sphere(current_sphere, head)))
		solutions = ft_intersect_ray_with_sphere(camera, point, current_sphere)
		IF (solutions->t1 >= tmin && solutions->t1 <= tmax && solutions->t1 < closest_t)
			closest_t = solutions->t1;
			closest_sphere = current_sphere;
		END IF
		IF (solutions->t2 >= tmin && solutions->t2 <= tmax && solutions->t2 < closest_t)
			closest_t = solutions->t2;
			closest_sphere = current_sphere;
		END IF
	END WHILE
	FREE(solutions);
	IF (closest_sphere == NULL)
		RETURN(background_color)
	END IF
	RETURN (closest_sphere.color)
END METHOD


