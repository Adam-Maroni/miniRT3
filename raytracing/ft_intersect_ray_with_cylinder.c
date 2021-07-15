#include "../minirt.h"

void ft_switch_float2_values(t_float2 *a)
{
	float t;
	t = a->t1;	
	a->t1 = a->t2;
	a->t2 = t;
}

void ft_init_float3(t_float3 *a, float value)
{
	a->x = value;	
	a->y = value;	
	a->z = value;	
}

t_float2 *ft_intersect_ray_with_cylinder_caps(t_float3 origin, t_float3 direction, t_float3 center, t_float3 normal, float radius, float height)
{
	t_float2 *tmp1;
	t_float2 *tmp2;
	t_float2 *solutions;

	solutions = (t_float2*)ft_calloc(1, sizeof(t_float2));
	tmp1 = ft_intersect_ray_with_disk(origin, direction, center, normal, radius);
	tmp2 = ft_intersect_ray_with_disk(origin, direction, ft_float3_plus_float3(center, ft_float_times_float3(height, normal)), normal, radius);
	solutions->t1 = tmp1->t1;
	solutions->t2 = tmp2->t1;
	free(tmp1);
	free(tmp2);
	return (solutions);

}

t_float2 *ft_intersect_ray_with_cylinder(t_float3 origin, t_float3 direction, t_list_minirt *cylinder)
{
	t_float3 normal;
	t_float3 center;
	t_float2 *solutions;
	t_float2 *tmp1;
	t_float2 *tmp2;
	t_float3 A; //Intersection parameter between cylinder normal and ray
	t_float3 Pi1; // Premiere Intersection avec la surface du cylindre
	t_float3 Pi2; // Seconde Intersection avec la surface du cylindre
	float radius;
	float height;
	float t;
	float t_prime;
	float step;
	

	ft_init_float3(&A, (float)INFINITY);
	ft_init_float3(&Pi1, (float)INFINITY);
	ft_init_float3(&Pi2, (float)INFINITY);
	normal = ft_get_shape_normal(cylinder);
	center = ft_get_shape_center(cylinder);
	radius = cylinder->content->parser_cylinder.cy_d / 2;
	height = cylinder->content->parser_cylinder.cy_h;
	step = 1/10;

	//Intersect with caps
	solutions = ft_intersect_ray_with_cylinder_caps(origin, direction, center, normal, radius, height);
	if (solutions->t1 < (float)INFINITY || solutions->t2 < (float)INFINITY)
		return (solutions);

	//Intersect with side
	tmp1 = ft_intersect_ray_with_plane(origin, direction, center, normal);
	tmp2 = ft_intersect_ray_with_plane(origin, direction, ft_float3_plus_float3(center, ft_float_times_float3(height, normal)), normal);
	solutions->t1 = tmp1->t1;
	solutions->t2 = tmp2->t1;
	free(tmp1);
	free(tmp2);
	//On check quel point d'intersection est le plus proche de l'origine
	if (solutions->t1 > solutions->t2)
	{
		ft_switch_float2_values(solutions);
		//center = ft_float3_plus_float3(center, ft_float_times_float3(height, normal));
	}
	//Check if ray pass by cylinder's normal
	t = solutions->t1;	
	while (t < solutions->t2)
	{
		t_prime = 0;
		while (t_prime < height)
		{
			if (ft_is_equal_float3(ft_float3_plus_float3(origin, ft_float_times_float3(t, direction)),ft_float3_plus_float3(center, ft_float_times_float3(t_prime, normal))))
			{
				A = ft_float3_plus_float3(origin, ft_float_times_float3(t, direction));
				break ;
			}
			t_prime = t_prime + step;
			printf("%f\n", t);
			printf("%f\n", t_prime);
		}
		t = t + step;
	}
	//IF it does
	if (ft_is_exist_float3(A))
	{
		t_float3 B = ft_float3_plus_float3(origin, ft_float_times_float3(solutions->t1, direction)); //Determines B
		float BC = ft_get_norm(ft_float3_minus_float3(B, center)); //Determines BC
		float AC = ft_get_norm(ft_float3_minus_float3(A,center));
		float AB = sqrt(AC * AC + BC * BC);
		float APi1 = radius / BC * AB;
		t = 0;
		while ( t < (float)INFINITY )
		{
			if (ft_get_norm(ft_float3_minus_float3(A, ft_float_times_float3(t,direction))) == APi1)
			{
				Pi1 = ft_float3_minus_float3(A, ft_float_times_float3(t,direction));
				break;
			}
			t +=  step;
		}
		Pi2 = ft_float3_plus_float3(A, ft_float_times_float3(t,direction));

		//Get ti1 and ti2 from Pi1 and Pi2
		t = 0;
		while (!ft_is_equal_float3(ft_float3_plus_float3(origin, ft_float_times_float3(t, direction)), Pi1) && t < (float)INFINITY)
			t += step;
		solutions->t1 = t;
		t = 0;
		while (!ft_is_equal_float3(ft_float3_plus_float3(origin, ft_float_times_float3(t, direction)), Pi2) && t < (float)INFINITY)
			t += step;
		solutions->t2 = t;
	}
	//IF it doesnt
	else
	{
		solutions->t1 = (float)INFINITY;
		solutions->t2 = (float)INFINITY;
	}
	return (solutions);
}
