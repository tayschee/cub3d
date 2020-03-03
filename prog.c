/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:21:10 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/03 16:37:20 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int *what_color(char c)
{
	long int color;
	int *tab;

	if (c == '1' || c == '3')
		color = RED;
	else if (c == '2')
		color = BLUE;
	else
		color = BLACK;
	tab = long_to_ORGB(color);
	return (tab);
}

static void print_view(t_all *data, int color)
{
	float i;
	double angle;
	char c;

	angle = - M_PI / 4;

	while(angle <= M_PI / 4)
	{
		i = 0;
		data->tchar.vvx = i * cos(data->tchar.view + angle);
		data->tchar.vvy = i * sin(data->tchar.view + angle);
		c = what_case(data, data->tchar.x + data->tchar.vvx,
		data->tchar.y + data->tchar.vvy) != '1';
		while (!(c == '1' || c == '3'))
		{
			mlx_pixel_put(data->twdw.ptr, data->twdw.win, data->tchar.x + data->tchar.vvx,
			data->tchar.y + data->tchar.vvy, color);
			data->tchar.vvx = i * cos(data->tchar.view + angle);
			data->tchar.vvy = i * sin(data->tchar.view + angle);
			c = what_case(data, data->tchar.x + data->tchar.vvx,
			data->tchar.y + data->tchar.vvy);
			i += 3;
		}
		angle += M_PI / 120; 	
	}
}

static void print_circle(t_all *data, int *ORGB, int ray)
{
	float i;
	double angle;
	int		k;
	int		pos_player;
	
	angle = 0;
	while(angle < 2 * M_PI)
	{
		i = 0;
		while (i < ray)
		{
			pos_player = (int)(data->tchar.x + i * cos(angle)) * 4 + data->twdw.size_line * (int)(data->tchar.y + i * sin(angle));
			k = 0;
			while(k < 4)
			{
				((unsigned char *)data->twdw.img_data)[(int)pos_player + k] = ORGB[3 - k];
				k++;
			}
			//mlx_pixel_put(data->twdw.ptr, data->twdw.win, data->tchar.x + i * cos(data->tchar.view + angle), data->tchar.y + i * sin(data->tchar.view + angle), color);
		i += 0.7; // je trouve ca ok pour le cercle
		}
		angle += M_PI / 480; // it's ok
	}
	free(ORGB);
}

void define_square(t_all *data, int *ORGB, int x, int y, int dimension)
{
	int 	i;
	int 	j;
	int		k;
	int pos_on_img;
	

	i = 0;
	while(i < dimension)
	{
		j = 0;
		while (j < dimension)
		{
			pos_on_img = (x + j) * 4 + data->twdw.size_line * (y + i);
			k = 0;
			while(k < 4)
			{
				((unsigned char *)data->twdw.img_data)[pos_on_img + k] = ORGB[3 - k]; //BGRO
				k++;
			}
			j++;
		}
		i++;
	}
		free(ORGB);
}

int minimap(t_all *data)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	y = 0;
	//data->twdw.img_ptr = mlx_new_image(data->twdw.ptr, data->twdw.width, data->twdw.height); // faire calc sup
	//data->twdw.img_data = mlx_get_data_addr(data->twdw.img_ptr, &data->twdw.bpp,
	//&data->twdw.size_line, &data->twdw.end); // pour empeche depassement
	while(data->tmap.map[i])
	{
		j = 0;
		x = 0;
		while(data->tmap.map[i][j])
		{
			//printf("fine\n");
			define_square(data, what_color(data->tmap.map[i][j]), x, y, DIMENSION);
			j++;
			x += DIMENSION;
		}
		i++;
		y += DIMENSION; 
	}
	print_circle(data, long_to_ORGB(GREEN), DIMENSION_PLAYER);
	mlx_put_image_to_window(data->twdw.ptr, data->twdw.win, data->twdw.img_ptr, 0, 0);
	print_view(data, TGREY);
	event(data);
	what_user_do(data);
	return (1);
}
