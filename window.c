/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wdw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:02:51 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/03 11:33:47 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	window(char *map, t_all *data)
{
	(void)map;
	data->twdw.ptr = mlx_init();
	data->twdw.img_ptr = mlx_new_image(data->twdw.ptr, data->twdw.width, data->twdw.height); // faire calc sup
	data->twdw.img_data = mlx_get_data_addr(data->twdw.img_ptr, &data->twdw.bpp,
	&data->twdw.size_line, &data->twdw.end); // pour empeche depassement
	data->twdw.win = mlx_new_window(data->twdw.ptr, data->twdw.width, data->twdw.height, "Ma fenetre");
	mlx_loop_hook(data->twdw.ptr, minimap, data);
	mlx_loop(data->twdw.ptr);
	//printf("%d\n%d\n", (int)mlx.ptr, (int)var.wdw.ptr);
}



