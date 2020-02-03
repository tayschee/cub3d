/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:28:02 by tbigot            #+#    #+#             */
/*   Updated: 2020/01/28 11:14:48 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		quit_esc(int keycode)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
		exit(0);
	return (keycode);
}

static int		quit_mouse()
{
	exit(1);
}

void	quit_prog(t_wdw	*wdw)
{
	mlx_hook(wdw->win, 2, 0, quit_esc, NULL);
	mlx_hook(wdw->win, 17, 0, quit_mouse, NULL);
}

