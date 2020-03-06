/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wdw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:02:51 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/06 15:19:15 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	window(char *map, t_all *data)
{
	(void)map;

	/*initialiser la fenetre*/
	data->twdw.ptr = mlx_init();
	data->twdw.win = mlx_new_window(data->twdw.ptr, data->twdw.width, data->twdw.height, "Ma fenetre");

	/*initialiser l'image*/
	data->twdw.img_ptr = mlx_new_image(data->twdw.ptr, data->twdw.width, data->twdw.height); // faire calc sup
	data->twdw.img_data = mlx_get_data_addr(data->twdw.img_ptr, &data->twdw.bpp,
	&data->twdw.size_line, &data->twdw.end); // pour empeche depassement

	/*mon programme*/
	mlx_loop_hook(data->twdw.ptr, minimap, data);

	/*refait chaque commande en boucle*/
	mlx_loop(data->twdw.ptr);
}
