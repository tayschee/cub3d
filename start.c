/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:36:06 by tbigot            #+#    #+#             */
/*   Updated: 2020/01/10 16:09:17 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <libc.h>

int what_exec(int nb_arg, char *v1)
{
	if ((nb_arg == 2 || nb_arg == 3))
	{
		if (nb_arg == 2)
			return (2);
		else if (!ft_strncmp(v1, "-save", 6))
			return (3);
	}
	return (1);
}

int main(int c, char **v)
{
	int i;
	char *map;
	
	i = what_exec(c, v[1]);
	if (i == 2)
	{
		printf("2 args\n");
		map = v[1];
	}
	else if (i == 3)
	{
		printf("3 args\n");
		map = v[2];
	}
	if (i == 2 || i == 3)
		check_map(map, i);
	else if (i == 1)
		perror("arguments not valid");
	return (0);
}
