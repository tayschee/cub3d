/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:53:48 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/03 13:37:10 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void position_player(char c, int x, int y, t_all *data)
{
	data->tchar.x = x * DIMENSION + DIMENSION / 2;
	data->tchar.y = y * DIMENSION + DIMENSION / 2;
	if (c == 'N')
		data->tchar.view = M_PI / 2;
	else if (c == 'S')
		data->tchar.view = - M_PI / 2;	
	if (c == 'W')
		data->tchar.view = M_PI;
	else if (c == 'E')
		data->tchar.view = 0;
	data->tchar.vx = cos(data->tchar.view);
	data->tchar.vy = sin(data->tchar.view);
	data->tchar.vvx = cos(data->tchar.view);
	data->tchar.vy = sin(data->tchar.view); //qwa ?
	//printf("vector : [%f][%f]\n", data->tchar.vx, data->tchar.vy); // c'est ;e bordel ?
}

static int	len_map(char *line)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (line && line[i])
	{
		if (line[i] == '1')
			count++;
		i++;
	}
	return (count);
}


static void		validchar(char *line, char *accept, int size, t_all *data, int y)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (line[++i])
	{
		j = -1;
		if (line[i] != ' ')
			count++;
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			if (data->tchar.view != -1)
				free_all(data, "Error2", 1);
			position_player(line[i], i, y, data);

		}
		while(accept[++j] != line[i])
		{
			if (accept[j] != line[i] && accept[j + 1] == '\0')
				free_all(data, "Error1", 1);
		}
	}
	if (size != count || line[0] != '1' || line[i - 1] != '1')
		free_all(data, "Error3", 1);
}

void	verifmap(t_all *data)
{
	int i;
	int size;

	i = 0;
	size = len_map(data->tmap.map[0]);
	if (size < 3)
		free_all(data, "Error5", 1);
	validchar(data->tmap.map[0], " 1", size, data, i);
	while(data->tmap.map[i + 1])
	{ 
		validchar(data->tmap.map[i], " 0WENS123456", size, data, i); //depend si il y a bien la texture des collectable des pieges a modifier
		i++;
	}
	if (data->tchar.view == -1)
		free_all(data, "Error4", 1);
	validchar(data->tmap.map[i], " 1", size, data, i);
	//while(1);
	//
	//printf("map is valid\n");
}
