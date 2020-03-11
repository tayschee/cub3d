/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:00:20 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/10 12:23:07 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char what_case(t_all *data, double x, double y)
{
	return (data->tmap.map[(int)(y)][(int)(x)]);
}

int check_player_position(t_all *data, double vx, double vy) //peut eventuellement etre ameliorer en les testant pas tous et en deplacant annuant uniquement le x ou le y en fonction de l'angle et ski il y a un mur
{
	double x;
	double y;

	data->tchar.vx = vx;
	data->tchar.vy = vy;
	x = data->tchar.x + vx;
	y = data->tchar.y + vy;
//	printf("x : %d\n y : %d\n", (int)(x + DIMENSION_PLAYER / 2) / DIMENSION == '1', (int)(y + DIMENSION_PLAYER / 2) / DIMENSION);
	if (data->tmap.map[(int)(y + DIMENSION_PLAYER / 2) / DIMENSION] 
	[(int)(x + DIMENSION_PLAYER / 2) / DIMENSION] == '1') /*arrive en diagonale sur un angle un peu bugue 😅*/
		return (0);
	data->tchar.x = x;
	data->tchar.y = y;
	data->tchar.vvx = vx;
	data->tchar.vvy = vy;
	//printf("%f\n%f\n", data->tchar.x, data->tchar.y);
	return (0);
}

//char check_ray(t_all *data)
