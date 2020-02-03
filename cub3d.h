/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:11:20 by tbigot            #+#    #+#             */
/*   Updated: 2020/02/03 14:53:40 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "./libft/libft.h" 

# define UP 13
# define DOWN 0
# define LEFT 2
# define RIGHT 1

# define ESC 53

#define RED 16711680
#define GREEN 2088960
#define BLUE 255
#define WHITE 16777215


typedef	struct		s_wdw
{
	void			*ptr;
	void			*win;
	int				height;
	int				width;

}					t_wdw;

typedef struct		s_map
{
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	char			*S;
	int				F;
	int				C;
	char			**map;

}					t_map;

typedef	struct		s_char
{
	char			card;
	int				x;
	int				y;
	
}					t_char;

typedef struct		s_all
{
	t_map			tmap;
	t_char			tchar;
	t_wdw			twdw;
}					t_all;

int		main(int c, char **v);

t_all	*initialise_struct_all();
void	free_all(t_all *all, char *msg, int i);

void	window(char *map, t_all *data);
void	quit_prog(t_all *data);
int		program(t_all *data);

void	parsing(char *file_name, t_all *data);
void	for_parsing_text(t_all *data, char *line);
void	verifmap(t_all *data);
void	verif_pars(t_all *data);


# endif
