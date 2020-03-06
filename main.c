/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:56:20 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/06 15:03:14 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_argv(int c, char **v)
{
	if (c == 3)
	{
		if (!ft_strncmp(v[1], "--save", 7) || !ft_strncmp(v[1], "--demo", 7))
			return (0);
		if (!ft_strncmp(v[1], "--save", 7)) 		
			return (2);
		else
			return (3);
	}
	if (c == 2)
		return (1);
	else
		return (0);
}


int		main(int c, char **v)
{
	char	*map;
	int		mode;
	t_all	*data;

	if ((mode = check_argv(c, v)) > 0)
	{
		data = 0;
		data = initialise_struct_all(mode);
		if (mode == 3)
			map = "a file"; //le nom de mon premier niveau
		map = v[c - 1];
		parsing(map, data);
		window(map, data);
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
