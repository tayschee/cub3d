/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:34:06 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/04 13:49:47 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*static void	end_map(t_all *data)
{
	(void)data;
}*/

void	event(t_all *data)
{
	//printf("data->tchar.y : %d\nx : %d\n", (int)(data->tchar.y / DIMENSION), (int)(data->tchar.x / DIMENSION));
	if (data->tmap.map[(int)(data->tchar.y / DIMENSION)][(int)(data->tchar.x / DIMENSION)] == '3') /*invisible wall*/
		data->tmap.map[(int)(data->tchar.y / DIMENSION)][(int)(data->tchar.x / DIMENSION)] = '0';
	//if (data->tmap.map[(int)data->tchar.y][(int)data->tchar.x] == '4') /*invisible wall*/
	//	end_map(data);
}


