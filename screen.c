#include "cub3d.h"

static void	write_bit(int fd, char *c, int size, int repeat)
{
	char char0;
	int j;

	char0 = 0;
	j = 0;
	if (c)
	{
		write(fd, c, size);
		j++;
	}
	while (j < repeat)
	{
		write(fd, &char0, 1);
		j++;
	}
}

static void	write_number_in_bit(int fd, int nb, int repeat)
{
	char c;
	int nb2;

	while (repeat-- > 0)
	{
		nb2 = nb;
		nb2 >>= 8;
		nb2 <<= 8;
		nb2 = nb - nb2;
		nb >>= 8;
		c = nb2;
		if (!nb2)
			write_bit(fd, NULL, 1, 1);
		else
			write_bit(fd, &c, 1, 1);	}
}

void		bit_map_file_header(int fd, int width, int height)
{
	int f_size;

	(void)f_size;
	f_size = width * height * 3;
	write_bit(fd, "BM", 2, 1);/*2 : File Type*/
	write_bit(fd, NULL, 1, 4);/*4 : File Size*/
	write_bit(fd, NULL, 1, 2);/*2 : Reserved*/
	write_bit(fd, NULL, 1, 2);/*Same*/
	write_bit(fd, "6", 1, 4);/*4 : Pixel Data Of Set*/

}

void		bit_map_in_fo_header(int fd, int width, int height)
{
	char	c1;
	int	bpp;
	int	f_size;

	(void)height;
	(void)c1;
	(void)bpp;
	(void)width;
	(void)f_size;
	//f_size = 24 * width / 32 * 4 * height;
	c1 = 1;
	bpp = 32;
	write_bit(fd, "(", 1, 4);/*4 : Header Size = 40 ('(' in ascci)*/
	write_number_in_bit(fd, width, 4);/*4 : Image Width*/
	write_number_in_bit(fd, height, 4);/*4 : Image Height*/
	write_bit(fd, &c1, 1, 2);/*2 : Planes = 1*/
	write_number_in_bit(fd, bpp, 2);/*2 : Bits per Pixels*/
	write_bit(fd, NULL, 1, 4);/*4 : Compression = 0*/
	write_number_in_bit(fd, 0, 4);/*4 : Image Size = 0*/
	write_bit(fd, NULL, 1, 4);/*4 : Xpixel Per Meter = 0*/
	write_bit(fd, NULL, 1, 4);/*4 : Ypixel Per Meter = 0*/
	write_number_in_bit(fd, 0, 4);/*4 : Total Colors*/
	write_bit(fd, NULL, 1, 4);/*4 : Important Colors = 0*/
}

void		screen(t_all *data)
{
	int fd;

	(void)data;
	fd = open("screen/test3.bmp", O_RDWR|O_CREAT|O_TRUNC, 0666);
	printf("fd : %d\n", fd);
	bit_map_file_header(fd, data->twdw.width, data->twdw.height);
	bit_map_in_fo_header(fd, data->twdw.width, data->twdw.height);
	bit_map_pixel_data(fd, data);
	close(fd);
	free_all(data, "ERROR", 0);
}
