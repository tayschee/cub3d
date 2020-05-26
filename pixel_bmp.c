#include "cub3d.h"

void	bit_map_pixel_data(int fd, t_all *data)
{
	int pos_on_img;
	int x;
	int y;
	int k;
	char c0 = 0;
	char c2 = 255;

	y = data->twdw.height - 1;
	(void)pos_on_img;
	(void)c0;
	(void)fd;
	(void)c2;
	while(y >= 0)
	{
		x = 0;
		while (x < data->twdw.width)
		{
			pos_on_img = x * 4 + y * data->twdw.size_line;
			k = 0;
			while(k < 4)
			{
			//	if(k == 2)
			//		write(fd, &c0, 1);
			//	else
			//		write(fd, &c2, 1);

			//	printf("k = %d\n", k);
				write(fd,
				&data->twdw.img_data[pos_on_img + k], 1);
				k++;
			}
			x++;
		}
		y--;
	}
}
