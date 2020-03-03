/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:55:26 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/02 13:33:44 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double pythagore(double c1, double c2)
{
	return(sqrt(c1 * c1 + c2 * c2));
}

int		*long_to_ORGB(long int color)
{
	int i;
	long int sub_color;
	int	*RGB;

	sub_color = 0;
	if(!(RGB = malloc(sizeof(int) * 4)))
		return (NULL);
	i = 0;
	while(++i <= 24)
	{
		if (color & 1 << (32 - i))
			sub_color = sub_color + pow(2, (24 - i));
	}
	sub_color = sub_color << 8;
	i = -1;
	while(++i < 4)
	{
		RGB[3 - i] = color - sub_color;
		color = color >> 8;
		sub_color = sub_color >> 16;
		sub_color = sub_color << 8;
	}
	return(RGB);
}

