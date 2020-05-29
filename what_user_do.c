/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_user_do.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:28:02 by tbigot            #+#    #+#             */
/*   Updated: 2020/05/28 14:42:18 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*static void		trigo(t_all *data)
{
	if (data->tchar.view > 2 * M_PI)
		data->tchar.view = data->tchar.view - 2 * M_PI;
	if (data->tchar.view < 0)
		data->tchar.view = 2 * M_PI + data->tchar.view;
}*/

static void		choice_screen(t_all *data, int keycode)
{
	if (keycode == TAB)
	{
		if (data->twdw.print_map == 1)
			data->twdw.print_map = 0;
		else
			data->twdw.print_map = 1;
	}
}

static int		input(int keycode, t_all *data)
{
	if (keycode == ESC)
		free_all(data, "ERROR", 0);
	choice_screen(data, keycode);
	if (keycode == UP)
	{
		check_player_position(data, SPEED * cos(data->tchar.view),
		SPEED * sin(data->tchar.view));
	}
	if (keycode == DOWN)
	{
		check_player_position(data,	SPEED * -1 * cos(data->tchar.view),
		SPEED * -1 * sin(data->tchar.view));
	}
	if (keycode == LEFT)
	{
		check_player_position(data,	SPEED * -1 *  cos(data->tchar.view + M_PI / 2), SPEED * -1
		* sin(data->tchar.view + M_PI / 2));
	}
	if (keycode == RIGHT)
	{
		check_player_position(data, SPEED * cos(data->tchar.view + M_PI / 2), SPEED
		* sin(data->tchar.view + M_PI / 2));
	}
	if (keycode == ROTATE_RIGHT)
		data->tchar.view += ROTATE_SPEED;
	if (keycode == ROTATE_LEFT)
		data->tchar.view -= ROTATE_SPEED;
	trigo_pi(data->tchar.view);
	data->tchar.vvx = cos(data->tchar.view);
	data->tchar.vvy = sin(data->tchar.view);
	what_case(data, data->tchar.x, data->tchar.y);
	return (keycode);
}

static int		quit_mouse(t_all *data)
{
	free_all(data, "ERROR", 0);
	return (0);
}

void			what_user_do(t_all	*data)
{
	mlx_hook(data->twdw.win, 2, 1L << 0, input, data);
	mlx_hook(data->twdw.win, 17, 1L << 0, quit_mouse, data);
}
