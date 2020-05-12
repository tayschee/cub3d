#include "cub3d.h"

static void print(t_all *data)
{
	double start_sprite;
	double dist_proj;
	//double proj_sprite;
	(void)data;

	dist_proj = DIMENSION * data->twdw.width / (2 * tan(M_PI / (3 * 2)));
	//proj_sprite = (DIMENSION / data->tvsprt->perp_dist) * dist_proj;
	start_sprite = (DIMENSION_SPRITE / data->tvsprt->dist) * dist_proj;
	//printf("sprite 1 %f\n", start_sprite);
	printf("sprite start %f\n", start_sprite);
	printf("data->twdw.height %d\n", data->twdw.height);


}

void	print_sprite(t_all *data)
{
	t_vsprt		*begin;

	closest_sprite_to_further(data);
	begin = data->tvsprt;
	while(data->tvsprt)
	{
		print(data);
		data->tvsprt = data->tvsprt->next;
	}
	data->tvsprt = begin;
}
