/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:36:06 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/12 16:47:45 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/wait.h>

static int		closest_wall(t_all *data)
{
	double tmp;

	data->twall.hyp = pythagore(data->tchar.x - data->twall.x,
	data->tchar.y - data->twall.y);

	tmp = pythagore(data->tchar.x - data->twall.xbis,
	data->tchar.y - data->twall.ybis);

	
	data->twall.x = data->twall.hyp > tmp
	? data->twall.xbis : data->twall.x;
	data->twall.y = data->twall.hyp > tmp
	? data->twall.ybis : data->twall.y;

	data->twall.hyp = data->twall.hyp > tmp ? tmp : data->twall.hyp;
	if (data->twall.hyp >= tmp)
		return (0); /*vertical*/
	return (1); /*horizontal*/
}

void	view(t_all *data, double v, int *color)
{
	int	i;
	double add;

	i = 0;
	add = - M_PI/6;
	if (!(data->tsprt.wray =
	malloc(sizeof(double) * data->twdw.width + 1)))
		free_all(data, "ERROR", 1);
	/*if (!(ray[1] = ft_calloc(sizeof(char) * data->twdw.width + 1)))
		free_all(data, "ERROR", 1);*/
	while(add <= M_PI / 6)
	{
		v = trigo_pi(data->tchar.view + add);
		check_horizontal(data, data->tchar.x, data->tchar.y, v);
		check_vertical(data, data->tchar.x, data->tchar.y, v);
		data->twall.horiz = closest_wall(data);
		//printf("i : %d\n", i);
		data->tsprt.wray[i] = data->twall.hyp * cos(add);
		print3d(data, i, v);
		if (data->twdw.print_map == 1)
			print_view_minimap(data, add, v, color);
		add += (M_PI / 3) / data->twdw.width;
		i++;

	}
	//while(1);
	//printf("begining\n");
	//printf("i : %d\n", i);
}
