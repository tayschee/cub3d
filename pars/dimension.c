/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:50:20 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/09 13:54:06 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	define_dimension(t_all *data, int map_w, int map_h)
{
	int map_size;
	//int screen_size;


	printf("size map : %d\n", data->twdw.dim_mini);
	printf("size char : %f\n", data->tchar.dim);
	map_size = data->twdw.width / map_w <= data->twdw.height / map_h ?
	data->twdw.width / map_w : data->twdw.height / map_h;
	//screen_size = data->twdw.height >= data->twdw.width
	//? data->twdw.height : data->twdw.width;

	//data->twdw.dim_mini *= screen_size / map_size; //c'est ok mais pas ouf trouve une formule magique
	data->twdw.dim_mini *= map_size; 	
	printf("size map : %d\n", data->twdw.dim_mini);
	data->tchar.dim *= data->twdw.dim_mini;
	printf("size char : %f\n", data->tchar.dim);
}
