/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:37:08 by tbigot            #+#    #+#             */
/*   Updated: 2020/01/29 11:49:29 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map	*initialise_struct_map()
{
	t_map *map;

	if(!(map = malloc(sizeof(map))))
		exit(1); //free_all + msg error
	map->NO = NULL;
	map->SO = NULL;
	map->WE = NULL;
	map->EA = NULL;
	map->F = -1;
	map->C = -1;
	map->map = 0;
	return(map);
}

static t_wdw	*initialise_struct_wdw()
{
	t_wdw *wdw;

	if(!(wdw = malloc(sizeof(wdw))))
		exit(1); //free_all + msg error
	wdw->ptr = 0;
	wdw->win = 0;
	wdw->height = -1;
	wdw->width = -1;
	return(wdw);
}

static t_char	*initialise_struct_char()
{
	t_char *charac;

	if(!(charac = malloc(sizeof(charac))))
		exit(1); //free_all + msg error
	charac->card = 'A';
	charac->x = -1;
	charac->y = -1;
	return(charac);
}

t_all	*initialise_struct_all()
{
	t_all	*all;

	if(!(all = malloc(sizeof(all))))
		exit(1); //free_all + msg error
	all->tmap =	initialise_struct_map();
	all->tchar = initialise_struct_char();
	all->twdw = initialise_struct_wdw();
	return (all);
}

/*void	free_all(t_all *all, char *msg, int i)
{
	printf("debut free\n");
	if (all)
	{
		printf("all sera free\n");
		
		if (all->twdw.ptr)
		{
			printf("ptr %s\n", all->twdw.ptr);
			free(all->twdw.ptr);
		}
		if (all->twdw.win)
		{
			printf("win %s\n", all->twdw.win);
			free(all->twdw.win);
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
		if (all->tmap.map)
		{ 
			printf("map : %s\n", all->tmap.map[0]);
			free(all->tmap.map);
		}
		free(all);
	}
	if (i == 1)
		perror(msg);
	exit(i);
}*/

