/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <tbigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:27:58 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/05 14:03:12 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		free_all2(t_all *all)
{
	if (all->tmap.we)
		mlx_destroy_image(all->twdw.ptr, all->tmap.we);
	if (all->tmap.ea)
		mlx_destroy_image(all->twdw.ptr, all->tmap.ea);
	if (all->tsprt.s)
		mlx_destroy_image(all->twdw.ptr, all->tsprt.s);
	if (all->tmap.map)
		free_malloc_2d(all->tmap.map);
	if (all->tsprt.wray)
		free(all->tsprt.wray);
	if (all->tvsprt)
		free_tvsprt(all);
	free(all);
}

void			free_all(t_all *all, char *msg, int i)
{
	printf("oh\n");
	if (all)
	{
		if (all->twdw.img_ptr)
			mlx_destroy_image(all->twdw.ptr, all->twdw.img_ptr);
		if (all->twdw.img_mn_ptr)
			mlx_destroy_image(all->twdw.ptr, all->twdw.img_mn_ptr);
		if (all->twdw.ptr)
		{
			if (!all->twdw.win)
			{
				printf("salut\n");
			//	all->twdw.win = mlx_new_window(all->twdw.ptr, 50, 50, "Cub3d");
			}
			mlx_destroy_window(all->twdw.ptr, all->twdw.win);
		}
		printf("ou\n");
		if (all->tmap.no)
			mlx_destroy_image(all->twdw.ptr, all->tmap.no);
		if (all->tmap.so)
			mlx_destroy_image(all->twdw.ptr, all->tmap.so);
		free_all2(all);
	}
	if (i == 1)
		write(i, msg, 6);
	exit(i);
}
