/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:21:10 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/11 18:34:29 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int *what_color(char c) /*met une couleur en fonction de ce qu'il y a sur la case*/
{
	long int color;
	int *tab;

	if (c == '1' || c == '3')
		color = RED;
	else if (c == '2')
		color = BLUE;
	else if (c == '4')
		color = GREEN;
	else if (c == '5')
		color = YELLOW;
	else if (c == '6')
		color = PURPLE;
	else
		color = BLACK;
	tab = long_to_ORGB(color);
	return (tab);
}

static void print_view(t_all *data, int color)
{
	double v;
	float i;
	float j;

	(void)color;
	(void)data;
	v = data->tchar.view + M_PI / 6;
	/*un petit while pour le faire avec toute les radiant*/
	while(v < data->tchar.view + M_PI / 6)
	{
		view(data, v); 
		//printf("pyt : %f\n", pyt);
		i = 0;
		j = 0;
		while (i < data->twall.hyp) //utiliser hyp struct
		{
			mlx_pixel_put(data->twdw.ptr, data->twdw.win, data->tchar.x * data->twdw.dim_mini + i * cos(v) * data->twdw.dim_mini,
			data->tchar.y * data->twdw.dim_mini + j * sin(v) * data->twdw.dim_mini, color);
			//printf("x print : %f\n", (data->tchar.x + i * data->tchar.vvx) * data->twdw.dim_mini);
			i += 0.1; //define une vraie valeur
			j += 0.1;
		}
		v += M_PI/192; //a modif;
	}
}

static void print_circle(t_all *data, int *ORGB, int ray, int dimension) /*modifier le ray en fonction de la taille*/
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
			pos_player = (int)(data->tchar.x * dimension + i * cos(angle)) * 4
			+ data->twdw.size_line * (int)(data->tchar.y * dimension + i * sin(angle)); // tout metrre * dimension ?
			k = 0;
			while(k < 4)
			{
				((unsigned char *)data->twdw.img_mn_data)[(int)pos_player + k] = ORGB[3 - k];
				k++;
			}
		i += 0.7; /*trouve une formule quand la taille change*/
		}
		angle += M_PI / 480; /*trouve une formule quand la taille change*/
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
	//printf("y : %f\n", data->tchar.y);
	//printf("x : %f\n", data->tchar.x);
	while(i < dimension)
	{
		j = 0;
		while (j < dimension)
		{
			pos_on_img = (int)((x * dimension + j)) * 4 + data->twdw.size_line
			* (int)((y * dimension + i));
			k = 0;
			while(k < 4)
			{
				((unsigned char *)data->twdw.img_mn_data)[pos_on_img + k] = ORGB[3 - k]; //BGRO
				k++;
			}
			j++;
		}
		i++;
	}
		free(ORGB);
}

void	print_screen(t_all *data)
{
	if (data->twdw.print_map == 1)
		mlx_put_image_to_window(data->twdw.ptr, data->twdw.win, data->twdw.img_mn_ptr, 0, 0);
	else if (data->twdw.print_map == 0)
		mlx_put_image_to_window(data->twdw.ptr, data->twdw.win, data->twdw.img_ptr, 0, 0);
}

int minimap(t_all *data)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	y = 0;
	while(data->tmap.map[i])
	{
		j = 0;
		x = 0;
		while(data->tmap.map[i][j])
		{
			define_square(data, what_color(data->tmap.map[i][j]), x, y, data->twdw.dim_mini);
			j++;
			x += DIMENSION;
		}
		i++;
		y += DIMENSION; 
	}
	print_circle(data, long_to_ORGB(GREEN), data->tchar.dim, data->twdw.dim_mini);
	event(data);
	print_screen(data);
	print_view(data, TGREY);
	what_user_do(data);
	return (1);
}
