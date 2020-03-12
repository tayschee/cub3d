/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:44:40 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/12 18:32:39 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print3d(t_all *data, int x)
{
	int		pos_on_img;
	int		ORGB[4] = {0, 0, 255, 0};
	int k = 0;
	double	dist_plane;

	dist_plane = (data->twdw.width / 2) / tan(60 / 2);
	data->twall.size = DIMENSION / data->twall.hyp * dist_plane;
	while(data->twall.size)
	{
		pos_on_img = (int)((x)) * 4 + data->twdw.size_line
		* (int)(- (data->twall.size / 2));
		k = 0;
		while(k < 4)
		{
			((unsigned char *)data->twdw.img_data)[pos_on_img + k] = ORGB[3 - k]; //BGRO
			k++;
		}
		data->twall.size--;
	}
}
