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

void	event(t_all *data)
{
	if (data->tmap.map[(int)(data->tchar.y / DIMENSION)]
	[(int)(data->tchar.x / DIMENSION)] == '3')
		data->tmap.map[(int)(data->tchar.y / DIMENSION)]
		[(int)(data->tchar.x / DIMENSION)] = '0';
}
