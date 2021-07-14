#include "../minirt.h"

t_float2 *ft_intersect_ray_with_cylinder(t_float3 origin, t_float3 direction, t_list_minirt *cylinder)
{
	t_float3 normal;
	t_float3 center;
	t_float2 *solutions;
	t_float2 *tmp1;
	t_float2 *tmp2;
	float radius;
	float height;
	float t;
	float t_prime;
	
	t_float3 A; //Intersection parameter between cylinder normal and ray
	t_float3 Pi1; // Premiere Intersection avec la surface du cylindre
	t_float3 Pi2; // Seconde Intersection avec la surface du cylindre

	//Initialiser A a INFINITY
	A = (float)INFINITY;
	normal = ft_get_shape_normal(cylinder);
	center = ft_get_shape_center(cylinder);
	radius = ft_get_shape_radius(cylinder);
	height = cylinder->content->parser_cylinder.cy_h;

	//Intersect with caps
	tmp1 = ft_intersect_ray_with_disk(origin, direction, center, normal, radius);
	tmp2 = ft_intersect_ray_with_disk(origin, direction, ft_float3_plus_float3(center, ft_float_times_float3(height, normal)), normal, radius);
	solutions->t1 = tmp1.t1;
	solutions->t2 = tmp2.t1;
	free(tmp1);
	free(tmp2);
	if (solutions->t1 < (float)INFINITY || solutions->t2 < (float)INFINITY)
		return (solutions);

	//Intersect with side
	tmp1 = ft_intersect_ray_with_plane(origin, direction, center, normal);
	tmp2 = ft_intersect_ray_with_plane(origin, direction, ft_float3_plus_float3(center, ft_float_times_float3(height, normal)), normal);
	solutions->t1 = tmp1.t1;
	solutions->t2 = tmp2.t1;
	free(tmp1);
	free(tmp2);
	//On check qule point d'intersection est le plus proche de l'origine
	if (solutions->t1 > solutions->t2)
	{
		t = solutions->t1;	
		solutions->t1 = solutions->t2;
		solutions->t2 = t;
		center = ft_float3_plus_float3(center, ft_float_times_float3(height, normal));
	}
		//Check if ray pass by cylinder's normal
	t = solutions->t1;	
	while (t < solutions->t2)
	{
		t_prime = 0;
		while (t_prime < height)
		{
			if (ft_float3_plus_float3(origin, ft_float_times_float3(t, direction)) == ft_float3_plus_float3(center, ft_float_times_float3(t_prime, normal)))
			{
				A = ft_float3_plus_float3(origin, ft_float_times_float3(t, direction));
				break ;
			}
			t_prime += 1/1000;
		}
		t += 1/1000;
	}
	//IF it does
	if (A < (float)INFINITY)
	{
		float B = ft_float3_plus_float3(origin, ft_float_times_float3(solutions->t1, direction)); //Determines B
		float BC = ft_get_norm(ft_float3_minus_float3(B, center)); //Determines BC
		float AC = ft_get_norm(ft_float3_minus_float3(A,c));
		float AB = sqrt(AC * AC + BC * BC);
		float APi1 = radius / BC * AB;
		t = 0;
		while ( t < (float)INFINITY )
		{
			if (ft_get_norm(ft_float3_minus_float3(A, ft_float_times_float3(direction,t))) == APi1);
			{
				Pi1 = ft_float3_minus_float3(A, ft_float_times_float3(direction,t));
				break;
			}
			t +=  1/1000;
		}
		Pi2 = ft_float3_plus_float3(A, ft_float_times_float3(direction,t));

		//Get ti1 and ti2 from Pi1 and Pi2
		t = 0;
		while (ft_float3_plus_float3(origin, ft_float_times_float3(t, direction)) != Pi1 && t < (float)INFINITY)
			t += 1/1000;
		solutions->t1 = t;
		t = 0;
		while (ft_float3_plus_float3(origin, ft_float_times_float3(t, direction)) != Pi2 && t < (float)INFINITY)
			t += 1/1000;
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
