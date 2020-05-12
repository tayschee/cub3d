#include "cub3d.h"


static void	print_screen(t_all *data)
{
	if (data->twdw.print_map == 1)
		mlx_put_image_to_window(data->twdw.ptr, data->twdw.win, data->twdw.img_mn_ptr, 0, 0);
	else if (data->twdw.print_map == 0)
		mlx_put_image_to_window(data->twdw.ptr, data->twdw.win, data->twdw.img_ptr, 0, 0);
	
}

int raycasting(t_all *data)
{
	view(data, data->tchar.view, long_to_ORGB(TGREY));
	//printf("allez\n");
	//while(1);
	print_sprite(data);
	map_without_X(data);
	free_tvsprt(data);
	print_screen(data);
	//while(1);
	event(data);
	what_user_do(data);
	return (0);
}
