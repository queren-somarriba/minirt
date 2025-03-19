#include "minirt.h"

int	print_scene(t_minirt *data)
{
	if (data->scene)
	{
		if (data->scene->amb)
		{
			printf("amb ratio=%.10f\n", data->scene->amb->ratio);
			printf("amb color r =%d\n", data->scene->amb->color->r);
			printf("amb color r =%d\n", data->scene->amb->color->g);
			printf("amb color r =%d\n\n", data->scene->amb->color->b);
		}
	}
	return (EXIT_SUCCESS);
}
