#include "cub3d.h"

double		pos_text(t_all *data)
{
	if (data->twall.horiz)
	{
		//printf("start text x : %f\n", data->twall.x - (int)data->twall.x);
		return (data->twall.x - (int)data->twall.x);
	}
	else
	{
		//printf("start text y : %f\n", data->twall.y - (int)data->twall.y);
		return (data->twall.y - (int)data->twall.y);
	}

}

int		apply_text(t_all *data, double proj_wall, double start_text, int y)
{
	int x;
	double	ratio;
	int pos_on_img;
	int begin_text;


	(void)begin_text;
	(void)start_text;
	(void)ratio;
	begin_text = (data->twdw.height - proj_wall) / 2 < 0 ? -(data->twdw.height - proj_wall) / 2 : 0;
	x = start_text * data->twall.width;
	//printf("x : ")
	ratio = data->twall.height / proj_wall;
	pos_on_img = 4 * x + data->twall.size_line * (int)((y + begin_text) * ratio);
	return (pos_on_img);
}

