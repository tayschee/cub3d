/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:09:12 by tbigot            #+#    #+#             */
/*   Updated: 2020/01/10 16:06:18 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
/*# include <sys/types.h>*/
/*# include <sys/stat.h>*/
# include <errno.h>

typedef struct	s_vmap
{
	int			hero;
	int			f_wall;
	int			l_wall;
}				t_vmap;

void	check_map(char *input, int screen);

# endif
