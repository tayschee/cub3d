#include "cub3d.h"

static int verif_black(t_all *data, int pos_on_text, char *txt, int x)
{
	int i = 0;

	(void)data;
	(void)x;
	
	printf("wall %f\nsprite %f\n", data->tsprt.wray[x + data->tsprt.left], data->tvsprt->dist);
	if (data->tsprt.wray[x + data->tsprt.left] < data->tvsprt->dist)
		return (-1);
	while (i < 3)
	{
		//printf("c : %d\n", txt[pos_on_text + i]);
		if (((unsigned char *)txt)[pos_on_text + i] != 0)
			return (0);
		i++;
	}
	return (1);
}
static int ratio_text(t_all *data, int x, int y, int pos_on_img)
{

	double ratio_x;
	double ratio_y;
	int pos_on_text;
	int k;
	int ret;
	

	(void)ratio_y;
	(void)ratio_x; 
	k = 0;
	ratio_x = (double)data->tsprt.dim_s[0] / data->twall.size;
	ratio_y = (double)data->tsprt.dim_s[1] / data->twall.size;
	//printf("width img : %d\n", data->tsprt.dim_s[0]);
	//printf("ratio_x %f\nratioy %f\n", ratio_x, ratio_y);
	pos_on_text = (int)(ratio_x * x) * 4 + data->tsprt.sl_s * (int)(y * ratio_y);
	//printf("pos_on_text : %d\n", pos_on_text);
	//printf("max size %d\n", data->tsprt.dim_s[0] * 4 + data->tsprt.sl_s * data->tsprt.dim_s[1]);
	printf("x %d\ny %d\n", (int)(x * ratio_x), (int)(y * ratio_y));

	if ((ret = !verif_black(data, pos_on_text, data->tsprt.S, x)))
	{
		//printf("salit salut\n");
		while (k < 4)
		{

			data->twdw.img_data[pos_on_img + k] 
			= data->tsprt.S[pos_on_text + k];
			k++;
		}
	}
	return (ret);
}

static void apply_sprite_text(t_all *data, int top, int left,
double sprite_size)
{
	int x;
	int y;
	int pos_on_img;
	int wall;

	x = left < 0 ? -left : 0;
	data->tsprt.left = left;
	data->twall.size = sprite_size;
	wall = data->tsprt.wray[0] < data->tvsprt->dist ? 1 : 0;
	//printf("x : %d\n", x);
	//printf("x + left %d\n", x + left);
	while(x < sprite_size && x + left < data->twdw.width)
	{
		y = top < 0 ? -top : 0;
		//printf("y : %d\n", y);
		while(y < sprite_size && y + top < data->twdw.height)
		{
			pos_on_img = (x + left) * 4 + data->twdw.size_line
			* (y + top);
			if (ratio_text(data, x, y, pos_on_img) < 0 && !wall)
			{
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				return ;
			}
			y++;
		}
		x++;
	}
}

static void define_position_sprite_on_window(t_all *data)
{
	double	sprite_dir;
	double	sprite_size;
	int	top_sprt;
	int	left_sprt;

	sprite_dir = atan2(data->tvsprt->y - data->tchar.y, data->tvsprt->x - data->tchar.x);
	while(sprite_dir - data->tchar.view > M_PI)
		sprite_dir -= 2*M_PI;
	while(sprite_dir - data->tchar.view < -M_PI)
		sprite_dir += 2*M_PI;
	data->tvsprt->dist *= cos(sprite_dir - data->tchar.view);
	sprite_size = data->twdw.height / data->tvsprt->dist;
	top_sprt = data->twdw.height / 2 - sprite_size / 2;
	left_sprt = (sprite_dir - data->tchar.view) * (M_PI / 3)
	* (data->twdw.width) + (data->twdw.width / 2 - sprite_size / 2);
	//printf("top : %d\n", top_sprt);
	//printf("left : %d\n", left_sprt);
	//printf("sprite_size : %f\n", sprite_size);
	//data->tvsprt->dist *= cos(sprite_dir);
	apply_sprite_text(data, top_sprt, left_sprt, sprite_size);
}

void	print_sprite(t_all *data)
{
	t_vsprt		*begin;

	closest_sprite_to_further(data);
	begin = data->tvsprt;
	while(data->tvsprt)
	{
		define_position_sprite_on_window(data);
		data->tvsprt = data->tvsprt->next;
	}
	data->tvsprt = begin;
}
