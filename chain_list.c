#include "cub3d.h"

void		closest_sprite_to_further(t_all *data)
{
	t_vsprt	*point;
	t_vsprt	*begin;
	t_vsprt	*sprite;

	point = NULL;

	begin = data->tvsprt;
	while(data->tvsprt)
	{
		sprite = data->tvsprt;
		data->tvsprt = data->tvsprt->next;
		if (data->tvsprt && sprite->dist < data->tvsprt->dist)
		{
			if (begin == sprite)
				begin = data->tvsprt;
			sprite->next = data->tvsprt->next;
			data->tvsprt->next = sprite;
			if (point)
				point->next = data->tvsprt;
			data->tvsprt = begin;
			point = NULL;
			//printf("restart\n");
		}
		else
			point = sprite;
	}
	//printf("sucess\n");
	data->tvsprt = begin;
/*	while(data->tvsprt)
	{
		printf("data->tvsprt.next : %p\n", data->tvsprt);
		printf("data->tsprt->dist : %f\n", data->tvsprt->dist);
		data->tvsprt = data->tvsprt->next;
	}
	data->tvsprt = begin;*/
	printf("fine\n");
}

void		map_without_X(t_all *data)
{
	int i = 0;
	int j = 0;
	t_vsprt	*save;

	save = data->tvsprt;
/*	while(data->tmap.map[i])
	{
		j = 0;
		while(data->tmap.map[i][j])
		{
			printf("%c", data->tmap.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}*/
	while (data->tvsprt)
	{
		//printf("data->tsprite->c %c\n", data->tsprite->c);
		//printf("data->tsprite->x %d\n", data->tsprite->case_x);
		//printf("data->tsprite->y %d\n", data->tsprite->case_y);
		data->tmap.map[(int)data->tvsprt->y]
		[(int)data->tvsprt->x] = data->tvsprt->c;
		data->tvsprt = data->tvsprt->next;
	}
	i = 0;
	data->tvsprt = save;
	while(data->tmap.map[i])
	{
		j = 0;
		while(data->tmap.map[i][j])
		{
			printf("%c", data->tmap.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

static void	end_of_tvsprt(t_all *data, t_vsprt **sprite)
{
	t_vsprt *save;

	save = data->tvsprt;
	while(data->tvsprt)
	{
		*sprite = data->tvsprt;
		data->tvsprt = data->tvsprt->next;
	}
	//printf("sprite : %p\n", *sprite);
	data->tvsprt = save;
	/*if (*sprite)
	{
		printf("x func: %d\n", (*sprite)->case_x);
		printf("y func: %d\n", (*sprite)->case_y);
		printf("sprite exist\n");
	
	}*/
}

void		free_tvsprt(t_all *data)
{
	t_vsprt		*save;
	t_vsprt		*sprite;

	//printf("hey\n");
	sprite = data->tvsprt;
	save = data->tvsprt;
	//printf("ok\n");
	while (data->tvsprt)
	{
		//printf("x fix: %d\n", data->tvsprt->case_x);
		//printf("y fix: %d\n", data->tvsprt->case_y);
		while(data->tvsprt->next)
		{
			sprite = data->tvsprt;
			data->tvsprt = data->tvsprt->next;
		}
		if (sprite == data->tvsprt)
		{
		//	printf("ici\n");
			free(data->tvsprt);
			data->tvsprt = NULL;
			break;
		}
		else
		{
			//printf("x sprite: %d\n", data->tsprite->case_x);
			//printf("y sprite: %d\n", data->tsprite->case_y);
			free(sprite->next);
			sprite->next = NULL;
		}
		data->tvsprt = save;
	}
	//printf("salut\n");
}

void sprite(t_all *data, int posx, int posy, double v)
{
	t_vsprt		*save;
	t_vsprt		*new;
	t_vsprt		*sprt;


	printf("hello\n");
	sprt = NULL;
	end_of_tvsprt(data, &sprt);
	printf("data->tvsprt %p\n", data->tvsprt);
	if (!(new = malloc(sizeof(t_vsprt))))
		free_all(data, "ERROR", 1);
	new->x = posx / DIMENSION + (double)(DIMENSION) / 2;
	new->y = (int)(posy / DIMENSION) + (double)(DIMENSION)/2;
	printf("new->case_x : %f\n", new->x);
	printf("new->case_y : %f\n", new->y);
	new->dist_x = data->tchar.x - new->x;
	new->dist_y = data->tchar.y - new->y;
	//printf("hello\n");
	new->c = data->tmap.map[(int)new->y][(int)new->x];
	//printf("c : %c\n", new->c);
	data->tmap.map[(int)new->y][(int)new->x] = 'X';
	new->dist = pythagore(new->dist_x, new->dist_y); //* cos (v - data->tchar.view);
	new->angle = v;
	new->next = NULL;
//	printf("seems ok\n");
	if (!sprt)
		data->tvsprt = new;
	else
		sprt->next = new;
	save = data->tvsprt;
	while(data->tvsprt)
	{
		//printf("struct : %f\n", data->tvsprt->dist);
		data->tvsprt = data->tvsprt->next;
	}
	printf("\n\n");
	data->tvsprt = save;
	
//	printf("et c'est la fin");
}


