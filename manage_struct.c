/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:37:08 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/03 16:04:11 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map	initialise_struct_map()
{
	t_map map;

	//if(!(map = malloc(sizeof(map))))
	//	exit(1); //free_all + msg error
	map.NO = NULL;
	map.SO = NULL;
	map.WE = NULL;
	map.EA = NULL;
	map.S = NULL;
	map.F = -1;
	map.C = -1;
	map.CLT = NULL;
	map.T = NULL;
	map.map = NULL;
	return(map);
}

static t_wdw	initialise_struct_wdw()
{
	t_wdw wdw;

	//if(!(wdw = malloc(sizeof(wdw))))
	//	exit(1); //free_all + msg error
	wdw.ptr = NULL;
	wdw.win = NULL;
	wdw.height = -1;
	wdw.width = -1;
	wdw.x = 0;
	wdw.y = 0;
	wdw.bpp = 32;
	wdw.size_line = 2020; // a changer
	wdw.end = 0;
	wdw.img_ptr = NULL;
	wdw.img_data = NULL;
	return(wdw);
}

static t_char	initialise_struct_char()
{
	t_char charac;

	//if(!(charac = malloc(sizeof(charac))))
	//	exit(1); //free_all + msg error
	charac.view = -1;
	charac.vvx = -1;
	charac.vvy = -1;
	charac.vx = -1;
	charac.vy = -1;
	charac.x = -1;
	charac.y = -1;
	charac.timer = 60;
	charac.life = 100;
	charac.stamina = 100;
	return(charac);
}

t_all	*initialise_struct_all()
{
	t_cam	cam;
	t_all	*all;

	cam.view = -1;
	cam.vx_cam = - 1;
	cam.vy_cam = -1;
	if(!(all = malloc(sizeof(t_all))))
		exit(1); //free_all + msg error
	all->tmap =	initialise_struct_map();
	all->tchar = initialise_struct_char();
	all->twdw = initialise_struct_wdw();
	all->tcam = cam;
	//tab_int(all->cheat, -1, 10);
	//printf("%d\n", all->cheat[4]);
	return (all);
}

void	free_all(t_all *all, char *msg, int i)
{
	(void)all;
	if (all)
	{
		printf("all sera free\n");
		if (all->twdw.img_ptr)
		{
			printf("img_ptr %s\n", all->twdw.img_ptr);
			mlx_destroy_image(all->twdw.ptr, all->twdw.img_ptr);
			//printf("img_ptr %s\n", all->twdw.img_ptr);
		}	
		if (all->twdw.ptr)
		{
			mlx_destroy_window(all->twdw.ptr,all->twdw.win);
			printf("ptr %s\n", all->twdw.ptr);
		}
		if (all->tmap.NO)
		{
			printf("no %s\n", all->tmap.NO);
			free(all->tmap.NO);
		}
		if (all->tmap.SO)
		{
			printf("so %s\n", all->tmap.SO);
			free(all->tmap.SO);
		}
		if (all->tmap.WE)
		{
			printf("we %s\n", all->tmap.WE);
			free(all->tmap.WE);
		}
		if (all->tmap.EA)
		{
			printf("ea %s\n", all->tmap.EA);
			free(all->tmap.EA);
		}
		if (all->tmap.S)
		{
			printf("S %s\n", all->tmap.S);
			free(all->tmap.S);
		}
		if (all->tmap.map)
		{ 
			printf("map : %s\n", all->tmap.map[0]);
			free_malloc_2d(all->tmap.map);//free char *puis char **
		}
		if (all->tmap.T)
		{ 
			printf("T : %s\n", all->tmap.T);
			free(all->tmap.T);
		}
		if (all->tmap.CLT)
		{ 
			printf("CLT : %s\n", all->tmap.CLT);
			free(all->tmap.CLT);
		}
		free(all);
	}
	//while (1);
	if (i == 1)
		perror(msg);
	exit(i);
}

