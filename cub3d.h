/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:11:20 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/12 18:33:05 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <mlx.h> 
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
# define EYE 1 / 2
# define DIMENSION_PLAYER 0.2
# define DIMENSION_SPRITE 1
# define RATIO 3

# define SPEED 0.1
# define ROTATE_SPEED M_PI/24


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
	void			*img_mn_ptr;
	char			*img_mn_data;
	int				x;
	int				y;
	int				dim_mini;
	int				print_map;
	int			sl_no;
	int			sl_so;
	int			sl_we;
	int			sl_ea;
}					t_wdw;

typedef struct		s_map
{
	void			*no;
	void			*so;
	void			*we;
	void			*ea;
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	int				F;
	int				C;
	char			**map;
	int			dim_no[2];
	int			dim_so[2];
	int			dim_we[2];
	int			dim_ea[2];
}					t_map;

typedef struct		s_wall
{
	double			x;
	double			y;
	double			xbis;
	double			ybis;
	double			hyp;
	int			size_x;
	int			size_y;
	int				horiz;
	double			size;
	char			*text;
	int			size_line;
	int			width;
	int			height;
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
	float			dim;
	double			ray;
	
}					t_char;

typedef struct		s_sprt
{
	void			*s;
	void			*t;
	void			*c;
	char			*S;
	char			*T;
	char			*C;
	int			sl_s;
	int			sl_t;
	int			sl_c;
	int			dim_s[2];
	int			dim_t[2];
	int			dim_c[2];
	int			beg;
	double			*wray;
	int			left;
}			t_sprt;

typedef struct		s_vsprt
{
	
	double		x;
	double		y;
	double		dist_x;
	double		dist_y;
	char		c;
	double		dist;
	double		angle;
	struct s_vsprt	*next;

}			t_vsprt;

typedef struct		s_all
{
	t_map			tmap;
	t_char			tchar;
	t_wdw			twdw;
	t_wall			twall;
	t_sprt			tsprt;
	t_vsprt			*tvsprt;
	char			*line;
	int				mode;
}					t_all;

int		main(int c, char **v);

t_all	*initialise_struct_all(int mode);
void	free_all(t_all *all, char *msg, int i);

void	parsing(char *file_name, t_all *data);
void	for_parsing_text(t_all *data);
void	verifmap(t_all *data);
void	verif_pars(t_all *data);
void	check_void(t_all *data, int i, int j);
void	add_space(t_all *data);
void	define_dimension(t_all *data, int map_w, int map_h);

void	window(char *map, t_all *data);

int	raycasting(t_all *data);
void	view(t_all *data, double v, int *color);

void	check_horizontal(t_all *data, double x, double y, double v);
void	check_vertical(t_all *data, double x, double y, double v);

void	sprite(t_all *data, int posx, int posy, double v);
void	closest_sprite_to_further(t_all *data);
void	map_without_x(t_all *data);
void	free_tvsprt(t_all *data);

void	print_sprite(t_all *data);

void	print3d(t_all *data, int x, double angle);
double 	pos_text(t_all *data);
int	apply_text(t_all *data, double proj_wall, double start_text , int y);

void	print_view_minimap(t_all *data, double add, double v, int *color);
int	minimap(t_all *data);

void	what_user_do(t_all *data);
//trier jusque la
//void	define_square(t_all *data, int *ORGB, int x, int y, int dimension);

//void player_position_minimap(t_all *data);

//int		*tab_int(int *tab, int c, int len);

void	screen(t_all *data);
void	bit_map_pixel_data(int fd, t_all *data);
char	what_case(t_all *data, double x, double y);
int		check_player_position(t_all *data, double vx, double vy);

double	pythagore(double c1, double c2);
int		*long_to_orgb(long int color);
double	trigo_pi(double angle);
int	verifchar(char c, char *valid);

void	event(t_all *data);



# endif
