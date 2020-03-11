/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:36:06 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/11 18:34:31 by tbigot           ###   ########.fr       */
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

void	view(t_all *data, double v)
{
	if (fabs(sin(v)) > 0.000001)
	{
		printf("ok\n");
		check_horizontal(data, data->tchar.x, data->tchar.y, v);
	}
	else
	{
		data->twall.y = 1000000000000000000;
		data->twall.x = 1000000000000000000;
	}
	if (fabs(cos(v)) > 0.000001)
	{
		check_vertical(data, data->tchar.x, data->tchar.y, v);
	}
	else
	{
		data->twall.ybis = 1000000000000000000;
		data->twall.xbis = 1000000000000000000;
	}
	closest_wall(data);
	//data->twall.hyp = pythagore(data->tchar.x - data->twall.x,
	//data->tchar.y - data->twall.y);
	printf("data->twall.hyp %f\n", data->twall.hyp);
}
