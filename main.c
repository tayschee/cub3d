#include "cub3d.h"

static int	check_argv(int c, char **v)
{
	if (c == 3)
	{
		if (ft_strncmp(v[1], "-save", 6))
			return (0);
	}
	if (c == 2 || c == 3)
	{
		//if (checkmap(v[m]))
		return (1);
	}
	else
		return (0);
}


int		main(int c, char **v)
{
	t_all	*data;

	if (check_argv(c, v) == 1)
	{
		data = 0;
		data = initialise_struct_all();
		/*printf("charac.card %c\n", data->tchar.card); //aretirer
		printf("charac.x %d\n", data->tchar.x);
		printf("charac.y %d\n", data->tchar.y);
		printf("wdw.ptr %p\n", data->twdw.ptr);
		printf("wdw.win %p\n", data->twdw.win);
		printf("wdw.height %d\n", data->twdw.height);
		printf("wdw.width %d\n", data->twdw.width);
		printf("map.NO %s\n", data->tmap.NO);
		printf("map.SO %s\n", data->tmap.SO);
		printf("map.WE %s\n", data->tmap.NO);
		printf("map.EA %s\n", data->tmap.SO);
		printf("map.F %d\n", data->tmap.F);
		printf("map.C %d\n", data->tmap.C);
		printf("map.map %p\n", data->tmap.map); //tpout ca*/
		parsing(v[c - 1], data);
		//window(v[c - 1]);
		return (0);// following program
	}
	else
	{
		return (1);
		//message erreur
		//return 1
	}
	return (0);
}
