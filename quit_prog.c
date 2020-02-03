/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:28:02 by tbigot            #+#    #+#             */
/*   Updated: 2020/02/03 14:54:10 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		quit_esc(int keycode, t_all *data)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
		free_all(data, "ERROR", 0);
	return (keycode);
}

static int		quit_mouse(t_all *data)
{
	free_all(data, "ERROR", 0);
	return(0);
}

void	quit_prog(t_all	*data)
{
	mlx_hook(data->twdw.win, 2, 0, quit_esc, data);
	mlx_hook(data->twdw.win, 17, 0, quit_mouse, data);
}

