/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:21:10 by tbigot            #+#    #+#             */
/*   Updated: 2020/01/27 15:18:13 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		program(t_wdw *wdw)
{
	int color;
	int x;
	int y;

	y = 0;
	x = 0;
	color = WHITE;
	while (y < wdw->height)
	{
		x = 0;
		if (y > wdw->height / 2)
			color = GREEN;
		while (x < wdw->width)
		{
			mlx_pixel_put(wdw->ptr, wdw->win, x, y, color);
			x++;
		}
		y++;
	}

	quit_prog(wdw);
	return(0);
}
