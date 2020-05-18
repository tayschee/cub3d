#include "cub3d.h"

void	bit_map_pixel_data(int fd, t_all *data)
{
	int pos_on_img;
	int x;
	int y;
	int k;
	char c0 = 0;

	y = 1;
	//y = 5;
	(void)pos_on_img;
	(void)c0;
	(void)fd;
	while(y > 0)
	{
		x = 0;
		while(x < 1)
		{
			pos_on_img = x * 4 + y * data->twdw.size_line;
			k = 1;
			while(k < 4)
			{
				//write(fd,
				//&data->twdw.img_data[pos_on_img + k], 1);
			//	write(fd, &c0, 1);
				k--;
			}
			x++;
		}
	}
}
