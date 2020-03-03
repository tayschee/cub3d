/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:52:02 by tbigot            #+#    #+#             */
/*   Updated: 2020/02/25 13:55:53 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int move_player(int keycode, t_all *data)
{
	printf("here\n");
	if (keycode == UP)
		data->tchar.y += 1;
	if (keycode == DOWN)
		data->tchar.y -= 1;
	if (keycode == LEFT)
		data->tchar.x -= 1;
	if (keycode == RIGHT)
		data->tchar.x += 1;
	print_square(data, GREEN, data->tchar.x, data->tchar.y, DIMENSION_PLAYER);
	printf("x after input: %f\n", data->tchar.x);
	return (keycode);
}

void player_position_minimap(t_all *data)
{
	//printf("marche?\n");
	mlx_hook(data->twdw.win, 3, 0, move_player, data);
	//printf("x : %f\n, y : %f\n", data->tchar.x, data->tchar.y);
}
