/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:36:06 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/06 15:32:17 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*double	check_horizontal(t_all *data, double axe1, double axe2, double w_axe1, double w_axe2)
{
	double hyp;
	int	down;
	int right;

	down = 0;
	right = 0; 
	(void)data;

	if (v > 0 && v < M_PI)
		down = 1;
	if (v > 3 * M_PI / 2 && v < M_PI / 2)
		right = 1;
	ay = (int)(y / DIMENSION) * DIMENSION;
	ay += down ? DIMENSION : 0;
	printf("y : %f\nay : %f\n", y, ay);
	ax = x + ((ay - y) / tan(v)); //pas sur
	//hyp = pythagore(ax, ay);
	printf("x : %f\nax : %f\n", x, ax);
	//check_next(down, right, v )
	//printf("inter %f\n", first_inter);
	return (ax);
}

double check_next(t_all data, int down, int right, double v)
{
	int y_step;
	int x_step;

	y_step = DIMENSION;
	y_step *= down ? 1 : -1;

	x_step = DIMENSION / tan(v);
	x_step *= !right && x_step > 0 ? -1 : 1;
	x_step *= right && x_step < 0 ? -1 : 1;
	while()
	{
		if (what_case(data, x + ax, y + ay) == '1'
		|| what_case(data, x + ax, y + ay) == '3')
			return();


}*/

/*double	check_vertical(t_all *data, double x, double y, double v)
{
	double ax;
	double ay;
	double first_inter;

	(void)data;
	ax = (int)(x) / DIMENSION * DIMENSION;
	printf("x : %f\nax : %f\n", x, ax);
	ay = y + ((x - ax) / tan(v)); //pas sur
	printf("y : %f\nay : %f\n", y, ay);
	first_inter = pythagore(ax, ay);
	//if (what_case(data, x + ax, y + ay) == '1'
	//|| what_case(data, x + ax, y + ay) == '3')
	//	return (first_inter);
	printf("inter %f\n", first_inter);
	return (first_inter);
}*/

/*double	check_horizontal(t_all *data, double pos, double v)
{
	double hyp;
	double inter;
	double size;
	int i;
	int j;

	i = -1;
	j = 0;
	size = 0;
	printf("vx : %f\n", v);
	printf("view : %f\n", cos(M_PI / 2));
	while (pos < data->twdw.height - DIMENSION/2)
	{
		//printf("posx : %f\n", posx);
		if ((int)pos % DIMENSION == 0)
			j = 1;
		if (v > 0)
			i = 1;
		inter = i * pos - i * DIMENSION * ((int)(pos - j) / DIMENSION);
		printf("inter : %f\n", inter);
		hyp = pythagore(inter, tan(v) * inter);
		size += hyp;
		printf("size : %f\n\n", size);
		pos += hyp * sin(v);
		if (what_case(data, data->tchar.x + size * cos(v), pos + i) == '1'
		|| what_case(data, data->tchar.x + size * cos(v), pos + i) == '3')
		{
			//printf("break\n\n\n\n\n");
			break;
		}
	}
	return (size);
}*/

/*void	view(t_all *data)
{
	double hyp = 214783647;
	double tmp = 214783647;

	if (fabs(data->tchar.vvy) > 0.00001)
	{
		//printf("hey\n");
		hyp = check_horizontal(data, data->tchar.x, data->tchar.y,
		data->tchar.view);
		printf("y : %f\n", hyp);
	}
	else
		tmp = 0;*/
	/*if (fabs(data->tchar.vvy) > 0.00001)
	{
		tmp = check_vertical(data, data->tchar.x, data->tchar.y,
		data->tchar.view);
		printf("x: %f\n", tmp);
	}*/
/*	if (fabs(tmp) < fabs(hyp))
		hyp = tmp;
	tmp = 0;
	printf("hyp %f\n", hyp);
	while(tmp < hyp)
	{
		mlx_pixel_put(data->twdw.ptr, data->twdw.win, data->tchar.x + (int)(tmp * 
		data->tchar.vvx), data->tchar.y + (int)(tmp * data->tchar.vvy), WHITE);
		tmp++;
	}
	printf("hyp == %f\n", hyp);
	//check_vertical(t_all *data);
}*/

