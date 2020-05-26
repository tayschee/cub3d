#include "cub3d.h"

/*static int ratio_text(t_all *data, int x, int y, int sprite_height)
{
	int pos_on_text;
	double ratio;

	//if (data->tsprt.stop_sprt < 0 && )
	ratio = DIMENSION_SPRITE / sprite_height;
	pos_on_text = x * ratio * 4 + data->tsprt.sl_s * y * ratio;
	return (pos_on_text);
}*/

static void apply_sprite_text(t_all *data, int top, int left,
double sprite_height)
{
	int x;
	int y;
	int pos_on_img;
	int k;
	int pos_on_text;
	int	ORGB[4] = {0, 255, 255, 255};

	(void)ORGB;
	(void)pos_on_text;
	y = 0;
	while(y < sprite_height && y < data->twdw.height)
	{
		x = 0;
		while(x < sprite_height && x < data->twdw.width)
		{
			//printf("x : %d\n", x + left);
			pos_on_img = (x + left) * 4 + data->twdw.size_line * (top + y);
		//	pos_on_text = ratio_text(data, x, y, sprite_height);
			k = 0;
			while (k++ < 4)
			{
				//data->twdw.img_data[pos_on_img + k]
				//= data->tsprt.S[pos_on_text + k];
				data->twdw.img_data[pos_on_img + k]
				= ORGB[3 - k];
			}
			//printf("salut1\n");
			//printf("y : %f\n", y);
			//mlx_pixel_put(data->twdw.ptr, data->twdw.win, (int)(left + x), (int)(top + y), GREEN);
			x++;
		}
		//while(1);
		y++;
	}
	//printf("ici\n");
}

static void define_position_sprite_on_window(t_all *data)
{
	double	sprite_dir;
	double	sprite_height;
	int	top_sprt;
	int	left_sprt;
	double angle;

	(void)angle;
	(void)sprite_dir; 
	angle = data->tchar.view; /*M_PI / 6 + data->tvsprt->angle*/;
	//data->tvsprt->angle = angle;
	//data->tvsprt->angle = data->tchar.view;
	sprite_dir = atan2(data->tvsprt->y - data->tchar.y, data->tvsprt->x - data->tchar.x);
	printf("sprite_dir : %f\n", sprite_dir);
	//trigo_pi(angle);
	while(sprite_dir - angle > M_PI)
		sprite_dir -= 2*M_PI;
	while(sprite_dir - angle < -M_PI)
		sprite_dir += 2*M_PI;
	printf("sprite_dir : %f\ndata->tchar.view : %f\ndata->tvsprt->angle%f\n", sprite_dir, data->tchar.view, angle);
	//while(1);*/
	sprite_height = data->twdw.height / data->tvsprt->dist;
	printf("height : %f\n", sprite_height);
	printf("sprite_height : %f\n", sprite_height);
	top_sprt = data->twdw.height / 2 - sprite_height / 2;
	left_sprt = (sprite_dir - angle) * (M_PI / 3) * data->twdw.width / 2 + data->twdw.width / 2 / 2- sprite_height / 2;
	printf("top_sprt : %d\n", top_sprt);
	printf("left_sprt %d\n", left_sprt);
	printf("angle : %f\n", angle);
	printf("widht : %d\n", data->twdw.width);
	apply_sprite_text(data, top_sprt, left_sprt, sprite_height);
	if (angle > 2 * M_PI)
		while(1);
}

void	print_sprite(t_all *data)
{
	t_vsprt		*begin;

	closest_sprite_to_further(data);
	begin = data->tvsprt;
	//data->tvsprt->angle = - 2 * M_PI / 2 - M_PI / 6;
	while(data->tvsprt)
	{
		define_position_sprite_on_window(data);
		data->tvsprt = data->tvsprt->next;
		printf("oh\n");
	}
	printf("ca\n");
	data->tvsprt = begin;
}
