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

static void		closest_wall(t_all *data)
{
	double tmp;


	data->twall.hyp = pythagore(data->tchar.x - data->twall.x,
	data->tchar.y - data->twall.y);

	tmp = pythagore(data->tchar.x - data->twall.xbis,
	data->tchar.y - data->twall.ybis);

	
	data->twall.x = data->twall.hyp > tmp ? data->twall.xbis : data->twall.x;
	data->twall.y = data->twall.hyp > tmp ? data->twall.ybis : data->twall.y;

	data->twall.hyp = data->twall.hyp > tmp ? tmp : data->twall.hyp;
}

void	view(t_all *data, double v, int *color)
{
	int	i;
	double add;

	i = 0;
	add = - M_PI/6;
	while(add <= M_PI / 6)
	{
		v = trigo_pi(data->tchar.view + add);
		check_horizontal(data, data->tchar.x, data->tchar.y, v);
		check_vertical(data, data->tchar.x, data->tchar.y, v);
		closest_wall(data);
		print3d(data, i);
		print_view_minimap(data, add, v, color);
		add += M_PI / data->twdw.width;
		i++;
	}
}
