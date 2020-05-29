/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:21:10 by tbigot            #+#    #+#             */
/*   Updated: 2020/05/29 15:37:26 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		*what_color(char c)
{
	long int	color;
	int			*tab;

	if (c == '1' || c == '3')
		color = RED;
	else if (c == 'X' || c == '2')
		color = BLUE;
	else
		color = BLACK;
	tab = long_to_orgb(color);
	return (tab);
}

static void			print_view_minimap(t_all *data,
double add, double *ray, int *color)
{
	float	i;
	int		k;
	int		pos_view;
	double	v;
	
	(void)add;
	i = 0;
	k = 0;
	v = trigo_pi(data->tchar.view - M_PI / 6);
	add = data->twdw.dim_mini /  M_PI/ 6; 
//	while (ray && *ray)
//	{		
		while (i < *ray)
		{
			pos_view = (int)(data->tchar.x * data->twdw.dim_mini + i
			* cos(v)) * 4 + data->twdw.size_line * (int)(data->tchar.y
			* data->twdw.dim_mini + i * sin(v));
			k = -1;
			while (++k < 4)
				data->twdw.img_mn_data[pos_view + k] = color[3 - k];
			i += 1;
		}
//		v = trigo_pi(v + add);
//		ray++;
//	}
//	free(color);
}

static void		print_circle(t_all *data, int *orgb, int ray, int dim)
{
	float	i;
	double	angle;
	int		k;
	int		pos_player;

	angle = 0;
	while (angle < 2 * M_PI)
	{
		i = 0;
		while (i < ray)
		{
			pos_player = (int)(data->tchar.x * dim + i * cos(angle)) * 4 +
			data->twdw.size_line * (int)(data->tchar.y * dim + i * sin(angle));
			k = 0;
			while (k < 4)
			{
				((unsigned char *)data->twdw.img_mn_data)
				[(int)pos_player + k] = orgb[3 - k];
				k++;
			}
			i += 0.7;
		}
		angle += M_PI / 480;
	}
	free(orgb);
}

static void		define_square(t_all *data,
int *orgb, int x, int y)
{
	int	i;
	int	j;
	int	k;
	int	pos_on_img;

	i = 0;
	while (i < data->twdw.dim_mini)
	{
		j = 0;
		while (j < data->twdw.dim_mini)
		{
			pos_on_img = (int)((x * data->twdw.dim_mini + j)) * 4 +
			data->twdw.size_line * (int)((y * data->twdw.dim_mini + i));
			k = 0;
			while (k < 4)
			{
				((unsigned char *)data->twdw.img_mn_data)
				[pos_on_img + k] = orgb[3 - k];
				k++;
			}
			j++;
		}
		i++;
	}
	free(orgb);
}

int				minimap(t_all *data, double add, double *ray, int *color)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	y = 0;
	(void)add;
	(void)ray;
	(void)color;
	while (data->tmap.map[i])
	{
		j = 0;
		x = 0;
		while (data->tmap.map[i][j])
		{
			define_square(data, what_color(data->tmap.map[i][j]), x, y);
			j++;
			x += DIMENSION;
		}
		i++;
		y += DIMENSION;
	}
	print_view_minimap(data, add, ray, color);
	print_circle(data, long_to_orgb(GREEN),
	data->tchar.dim, data->twdw.dim_mini);
	return (1);
}
