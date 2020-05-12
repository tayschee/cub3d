/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:28:02 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/12 14:00:30 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		trigo(t_all *data)
{
	printf("data->tcahr.view : %f\n", data->tchar.view);
	if (data->tchar.view > 2 * M_PI)
	data->tchar.view = data->tchar.view - 2 * M_PI;
	if (data->tchar.view < 0)
		data->tchar.view = 2 * M_PI + data->tchar.view;
	printf("data->tcahr.view : %f\n", data->tchar.view);
}

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
	printf("salut\n");
	printf("%d\n", keycode);
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
	trigo(data);
	data->tchar.vvx = cos(data->tchar.view);
	data->tchar.vvy = sin(data->tchar.view);
	printf("v[%f][%f]", data->tchar.vvx, data->tchar.vvy);
	//cheat(keycode, data);
	what_case(data, data->tchar.x, data->tchar.y);
	return (keycode);
}

static int		quit_mouse(t_all *data)
{
	printf("fine\n");
	free_all(data, "ERROR", 0);
	return(0);
}

static int test(int keycode, void *n)
{
	(void)n;
	(void)keycode;
	printf("salut test\n");
	return(keycode);
}
void	what_user_do(t_all	*data)
{
	//printf("%ld\n", (1L<<0));
	mlx_key_hook(data->twdw.win, test, NULL);
	mlx_hook(data->twdw.win, 2, 1L<<0, input, data);
	mlx_hook(data->twdw.win, 17, 1, quit_mouse, data);
}

