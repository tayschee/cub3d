/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <tbigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:28:43 by tbigot            #+#    #+#             */
/*   Updated: 2020/05/27 20:21:42 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_screen(t_all *data)
{
	if (data->mode == 2)
		screen(data);
	if (data->twdw.print_map == 1)
		mlx_put_image_to_window(data->twdw.ptr,
		data->twdw.win, data->twdw.img_mn_ptr, 0, 0);
	else if (data->twdw.print_map == 0)
		mlx_put_image_to_window(data->twdw.ptr,
		data->twdw.win, data->twdw.img_ptr, 0, 0);
}

int			raycasting(t_all *data)
{
	view(data, data->tchar.view, long_to_orgb(TGREY));
	print_sprite(data);
	map_without_x(data);
	free_tvsprt(data);
	print_screen(data);
	event(data);
	what_user_do(data);
	return (0);
}
