/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:28:02 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/03 14:16:11 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		input(int keycode, t_all *data)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
		free_all(data, "ERROR", 0);
	if (keycode == UP)
	{
		check_player_position(data, SPEED * cos(data->tchar.view),
		SPEED * sin(data->tchar.view));
	}
	if (keycode == DOWN)
	{
		check_player_position(data,	-SPEED * cos(data->tchar.view),
		-SPEED * sin(data->tchar.view));
	}
	if (keycode == LEFT)
	{
		check_player_position(data,	-SPEED * cos(data->tchar.view + M_PI/2),
		-SPEED * sin(data->tchar.view + M_PI/2));
	}
	if (keycode == RIGHT)
	{
		check_player_position(data, SPEED * cos(data->tchar.view + M_PI/2),
		SPEED * sin(data->tchar.view + M_PI/2));
	}
	if (keycode == ROTATE_RIGHT)
		data->tchar.view += ROTATE_SPEED;
	if (keycode == ROTATE_LEFT)
		data->tchar.view -= ROTATE_SPEED;
	data->tchar.vvx = cos(data->tchar.view);
	data->tchar.vvy = sin(data->tchar.view);
	//cheat(keycode, data);
	what_case(data, data->tchar.x, data->tchar.y);
	return (keycode);
}

static int		quit_mouse(t_all *data)
{
	free_all(data, "ERROR", 0);
	return(0);
}

void	what_user_do(t_all	*data)
{
	mlx_hook(data->twdw.win, 2, 0, input, data);
	mlx_hook(data->twdw.win, 17, 0, quit_mouse, data);
}

