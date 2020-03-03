/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:10:54 by tbigot            #+#    #+#             */
/*   Updated: 2020/02/26 12:23:05 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		*tab_int(int *tab, int c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		tab[i] = c;
		i++;
	}
	return (tab);
}

static int check_cheat(int *tab)
{
	(void)tab;
	return (0);
}

void cheat(int keycode, t_all *data)
{
	int i;

	i = 0;
	while(data->cheat[i] != -1 && i < 10)
	{
		i++;
	}
	if (i == 10)
	{
		i = 0;
		while (i < 9)
		{
			data->cheat[i] = data->cheat[i + 1];
			i++;
		}
	}
	data->cheat[i] = keycode;
	if (check_cheat(data->cheat))
		printf("CHEAT ACTIVATED");
}
