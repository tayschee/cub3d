/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wdw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:02:51 by tbigot            #+#    #+#             */
/*   Updated: 2020/01/27 16:07:08 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	window(char *map)
{
	t_wdw	wdw;

	(void)map;
	wdw.ptr = mlx_init();
	wdw.height = 500; // to define with file .cub
	wdw.width = 600; //same
	wdw.win = mlx_new_window(wdw.ptr, wdw.width, wdw.height, "Ma fenetre");
	mlx_loop_hook(wdw.ptr, program, &wdw);
	mlx_loop(wdw.ptr);
	//printf("%d\n%d\n", (int)mlx.ptr, (int)var.wdw.ptr);
}



