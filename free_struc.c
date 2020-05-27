/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <tbigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:27:58 by tbigot            #+#    #+#             */
/*   Updated: 2020/05/27 12:28:01 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_all *all, char *msg, int i)
{
	if (all)
	{
		if (all->twdw.img_ptr)
			mlx_destroy_image(all->twdw.ptr, all->twdw.img_ptr);
		if (all->twdw.img_mn_ptr)
			mlx_destroy_image(all->twdw.ptr, all->twdw.img_mn_ptr);
		if (all->twdw.ptr)
		{
			if (!all->twdw.win)
				all->twdw.win = mlx_new_window(all->twdw.ptr, 50, 50, "Cub3d");
			mlx_destroy_window(all->twdw.ptr, all->twdw.win);
		}
		if (all->tmap.no)
			mlx_destroy_image(all->twdw.ptr, all->tmap.no);
		if (all->tmap.so)
			mlx_destroy_image(all->twdw.ptr, all->tmap.so);
		if (all->tmap.we)
			mlx_destroy_image(all->twdw.ptr, all->tmap.we);
		if (all->tmap.ea)
			mlx_destroy_image(all->twdw.ptr, all->tmap.ea);
		if (all->tsprt.s)
			mlx_destroy_image(all->twdw.ptr, all->tsprt.s);
		if (all->tmap.map)
			free_malloc_2d(all->tmap.map);
		if (all->tsprt.t)
			mlx_destroy_image(all->twdw.ptr, all->tsprt.t);
		if (all->tsprt.c)
			mlx_destroy_image(all->twdw.ptr, all->tsprt.c);
		if (all->tsprt.wray)
			free(all->tsprt.wray);
		if (all->tvsprt)
			free_tvsprt(all);
		free(all);
	}
	if (i == 1)
		write(i, msg, 6);
	exit(i);
}
