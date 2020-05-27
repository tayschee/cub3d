/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:36:06 by tbigot            #+#    #+#             */
/*   Updated: 2020/05/27 12:50:49 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		return (0);
	return (1);
}

void			view(t_all *data, double v, int *color)
{
	int		i;
	double	add;

	i = 0;
	add = -M_PI / 6;
	if (!(data->tsprt.wray =
	malloc(sizeof(double) * data->twdw.width)))
		free_all(data, "ERROR", 1);
	while (i < data->twdw.width)
	{
		v = trigo_pi(data->tchar.view + add);
		data->tchar.ray = v;
		check_horizontal(data, data->tchar.x, data->tchar.y, v);
		check_vertical(data, data->tchar.x, data->tchar.y, v);
		data->twall.horiz = closest_wall(data);
		data->tsprt.wray[i] = data->twall.hyp * cos(add);
		print3d(data, i, v);
		if (data->twdw.print_map == 1)
			print_view_minimap(data, add, v, color);
		add += (M_PI / 3) / data->twdw.width;
		i++;
	}
}
