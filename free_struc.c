#include "cub3d.h"

void	free_all(t_all *all, char *msg, int i)
{
	(void)all;
	if (all)
	{
		printf("all sera free\n");
		if (all->twdw.img_ptr)
		{
			printf("img_ptr %p\n", all->twdw.img_ptr);
			mlx_destroy_image(all->twdw.ptr, all->twdw.img_ptr);
			//printf("img_ptr %s\n", all->twdw.img_ptr);
		}
		if (all->twdw.img_mn_ptr)
		{
			printf("img_ptr %p\n", all->twdw.img_ptr);
			mlx_destroy_image(all->twdw.ptr, all->twdw.img_mn_ptr);
			//printf("img_ptr %s\n", all->twdw.img_ptr);
		}
		if (all->twdw.ptr)
		{
			printf("ptr %p\n", all->twdw.ptr);
			if (!all->twdw.win)
				all->twdw.win = mlx_new_window(all->twdw.ptr, 50, 50, "Cub3d");
			mlx_destroy_window(all->twdw.ptr, all->twdw.win);
			//printf("ptr %s\n", all->twdw.ptr);
		}
		if (all->tmap.no)
		{
			printf("no %s\n", all->tmap.NO);
			mlx_destroy_image(all->twdw.ptr, all->tmap.no);
			//free(all->tmap.NO);
		}
		if (all->tmap.so)
		{
			printf("so %s\n", all->tmap.SO);
			mlx_destroy_image(all->twdw.ptr, all->tmap.so);
		}
		if (all->tmap.we)
		{
			printf("we %s\n", all->tmap.WE);
			mlx_destroy_image(all->twdw.ptr, all->tmap.we);
		}
		if (all->tmap.ea)
		{
			printf("ea %s\n", all->tmap.EA);
			mlx_destroy_image(all->twdw.ptr, all->tmap.ea);

		}
		if (all->tsprt.s)
		{
			//printf("S %s\n", all->tmap.S);
			mlx_destroy_image(all->twdw.ptr, all->tsprt.s);

		}
		if (all->tmap.map)
		{ 
			printf("map : %s\n", all->tmap.map[0]);
			free_malloc_2d(all->tmap.map);//free char *puis char **
		}
		if (all->tsprt.t)
		{ 
			//printf("T : %s\n", all->tmap.T);
			mlx_destroy_image(all->twdw.ptr, all->tsprt.t);

		}
		if (all->tsprt.c)
		{ 
			//printf("CLT : %s\n", all->tmap.CLT);
			mlx_destroy_image(all->twdw.ptr, all->tsprt.c);
		}
		if (all->tsprt.wray)
			free(all->tsprt.wray);
		if (all->tvsprt)
			free_tvsprt(all);		
		free(all);
	}
//	while (1);
	if (i == 1)
		perror(msg);
	exit(i);
}

