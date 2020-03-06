/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:11:20 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/06 18:32:36 by tbigot           ###   ########.fr       */
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
# include "math.h"

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2

# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124

# define ESC 53
# define TAB 48


# define RED 16711680
# define GREEN 2088960
# define BLUE 255
# define WHITE 16777215
# define BLACK 0
# define YELLOW 16776960
# define GREY 13882323
# define PURPLE 8388736
# define TGREY 2144588755


# define DIMENSION 1
# define DIMENSION_PLAYER 0.2
# define RATIO 3

# define SPEED 0.1
# define ROTATE_SPEED M_PI/12


typedef	struct		s_wdw
{
	void			*ptr;
	void			*win;
	int				height;
	int			    width;
	int				bpp;
	int				size_line;
	int				end;
	void			*img_ptr;
	char			*img_data;
	int				x;
	int				y;
	int				dim_mini;

}					t_wdw;

typedef struct		s_map
{
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	char			*S;
	char			*T;
	char			*CLT;
	int				F;
	int				C;
	char			**map;

}					t_map;

typedef struct		s_camera
{
	double		view;
	double		vx_cam;
	double		vy_cam;

}					t_cam;

typedef struct		s_wall
{
	double			x;
	double			y;
}					t_wall;

typedef	struct		s_char
{
	double			view;
	double			vvx;
	double			vvy;
	double			vx;
	double			vy;
	double			x;
	double			y;
	int				life;
	int				timer;
	int				stamina;
	float			dim;
	
}					t_char;

typedef struct		s_all
{
	t_map			tmap;
	t_char			tchar;
	t_wdw			twdw;
	t_cam			tcam;
	t_wall			twall;
	int				mode;
	//int				cheat[10];
}					t_all;

int		main(int c, char **v);

t_all	*initialise_struct_all(int mode);
void	free_all(t_all *all, char *msg, int i);

void	window(char *map, t_all *data);
void	define_dimension(t_all *data, int map_w, int map_h);
void	what_user_do(t_all *data);
int		minimap(t_all *data);
void	define_square(t_all *data, int *ORGB, int x, int y, int dimension);

void player_position_minimap(t_all *data);

void	parsing(char *file_name, t_all *data);
void	for_parsing_text(t_all *data, char *line);
void	verifmap(t_all *data);
void	verif_pars(t_all *data);

void	cheat(int keycode, t_all *data);
int		*tab_int(int *tab, int c, int len);

char	what_case(t_all *data, double x, double y);
int		check_player_position(t_all *data, double vx, double vy);

double	pythagore(double c1, double c2);
int		*long_to_ORGB(long int color);
int		pn(double nb);

void	event(t_all *data);

void	view(t_all *data);
double	check_horizontal(t_all *data, double x, double y, double v);
double	check_vertical(t_all *data, double x, double y, double v);


# endif
