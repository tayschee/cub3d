/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wdw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:02:51 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/12 13:27:53 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	window(char *map, t_all *data)
{
	data->twdw.ptr = mlx_init();
	parsing(map, data);
	data->twdw.win = mlx_new_window(data->twdw.ptr, data->twdw.width
	, data->twdw.height, "Cub3D");
	data->twdw.img_ptr =
	mlx_new_image(data->twdw.ptr, data->twdw.width, data->twdw.height);
	data->twdw.img_data =
	mlx_get_data_addr(data->twdw.img_ptr, &data->twdw.bpp,
	&data->twdw.size_line, &data->twdw.end);
	data->twdw.img_mn_ptr =
	mlx_new_image(data->twdw.ptr, data->twdw.width, data->twdw.height);
	data->twdw.img_mn_data = mlx_get_data_addr(data->twdw.img_mn_ptr,
	&data->twdw.bpp, &data->twdw.size_line, &data->twdw.end);
	mlx_loop_hook(data->twdw.ptr, raycasting, data);
	mlx_loop(data->twdw.ptr);
}
