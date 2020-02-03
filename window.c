/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wdw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:02:51 by tbigot            #+#    #+#             */
/*   Updated: 2020/02/03 14:47:00 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	window(char *map, t_all *data)
{
	(void)map;
	data->twdw.ptr = mlx_init();
	data->twdw.win = mlx_new_window(data->twdw.ptr, data->twdw.width, data->twdw.height, "Ma fenetre");
	mlx_loop_hook(data->twdw.ptr, program, data);
	mlx_loop(data->twdw.ptr);
	//printf("%d\n%d\n", (int)mlx.ptr, (int)var.wdw.ptr);
}



