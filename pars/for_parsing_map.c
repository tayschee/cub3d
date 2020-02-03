/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:53:48 by tbigot            #+#    #+#             */
/*   Updated: 2020/02/03 14:39:12 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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



static void		validchar(char *line, char *accept, int size, t_all *data)
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
			if (data->tchar.card != 'A')
				free_all(data, "Error2", 1);
			data->tchar.card = line[i];
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
	validchar(data->tmap.map[0], " 1", size, data);
	while(data->tmap.map[i + 1])
	{ 
		validchar(data->tmap.map[i], " 0WENS12", size, data);
		i++;
	}
	if (data->tchar.card == 'A')
		free_all(data, "Error4", 1);
	validchar(data->tmap.map[i], " 1", size, data);
	printf("map is valid\n");
}
