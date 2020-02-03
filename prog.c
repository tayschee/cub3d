/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:21:10 by tbigot            #+#    #+#             */
/*   Updated: 2020/02/03 14:48:51 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		program(t_all *data)
{
	int x;
	int y;
	int color;

	y = 0;
	x = 0;
	color = data->tmap.C;
	while (y < data->twdw.height)
	{
		x = 0;
		if (y > data->twdw.height / 2)
			color = data->tmap.F;
		while (x < data->twdw.width)
		{
			mlx_pixel_put(data->twdw.ptr, data->twdw.win, x, y, color);
			x++;
		}
		y++;
	}
	quit_prog(data);
	return(0);
}
