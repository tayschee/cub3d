/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:14:07 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/12 13:26:59 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	dimension_wdw(char *line, t_all *data) // tu devrais le refaire
{
	int i;

	i = 0;
	while (line[i] != ' ')
		i++;
	i++;
	data->twdw.width = ft_atoi(&line[i]);
	data->twdw.size_line = data->twdw.width * 4;
	while(line[i] != ' ')
		i++;
	i++;
	data->twdw.height = ft_atoi(&line[i]);
	if (data->twdw.width < 60)
	{
		free(line);
		free_all(data, "ERROR", 1);
	}
}

static int		color(char	*line, t_all *data) //tu devrais le refaire quand tu auras fini
{
	int i;
	int y;
	int x;

	i = 0;
	x = 0;
	while (line[i] != ' ')
		i++;
	i++;
	while(line[i] && i < 100)
	{
		x =	x << 8;
		y = ft_atoi(&line[i]);
		if (y > 255)
		{
			free(line);
			free_all(data, "ERROR1", 1);
		}
		x += y;
		while (verifchar(line[i], "0123456789") && line[i])
			i++;
		if (line[i] == ',')
			i++;
	}
	return(x);
}

static char	*path_to_text(t_all *data, int dim[2], void *dir, int *size_line)
{
	char **text;
	char *ret;

	//printf("line : %s\n", line);
	text = ft_split(data->line, ' ');
//	printf("data->tmap.width : %d\n", data->tmap.width);
	if(!(dir = mlx_xpm_file_to_image(data->twdw.ptr, text[1], &data->twall.width, &data->twall.height)))
	{
		free(data->line);
		free_malloc_2d(text);
		free_all(data, "ERROR", 1);
	}
//	printf("data->tmap.width 2 : %d\n", data->tmap.width);
	free_malloc_2d(text);
	ret = mlx_get_data_addr(dir, &data->twdw.bpp, size_line, &data->twdw.end);
	dim[0] = data->twall.width;
	dim[1] = data->twall.height;
	return(ret);
}


void	for_parsing_text(t_all *a)
{
	if(!ft_strncmp(a->line, "NO ", 3))
		a->tmap.NO = path_to_text(a, a->tmap.dim_no, a->tmap.no, &a->twdw.sl_no);
	else if(!ft_strncmp(a->line, "SO ", 3))
		a->tmap.SO = path_to_text(a, a->tmap.dim_so, a->tmap.so, &a->twdw.sl_so);
	else if(!ft_strncmp(a->line, "WE ", 3))
		a->tmap.WE = path_to_text(a, a->tmap.dim_we, a->tmap.we, &a->twdw.sl_we);
	else if(!ft_strncmp(a->line, "EA ", 3))
		a->tmap.EA = path_to_text(a, a->tmap.dim_ea, a->tmap.ea, &a->twdw.sl_ea);
	else if(!ft_strncmp(a->line, "R ", 2))
		dimension_wdw(a->line, a); // inclure un int maxx et minpour la taille de la fenetre
	else if(!ft_strncmp(a->line, "F ", 2))
		a->tmap.F = color(a->line, a);
	else if (!ft_strncmp(a->line, "C ", 2))
		a->tmap.C = color(a->line, a);
	else if(!ft_strncmp(a->line, "S ", 2))
		a->tsprt.S = path_to_text(a, a->tsprt.dim_s, a->tsprt.s, &a->tsprt.sl_s);
	else if (!ft_strncmp(a->line, "TRAP ", 5))
		a->tsprt.T = path_to_text(a, a->tsprt.dim_t, a->tsprt.t, &a->tsprt.sl_t);
	else if (!ft_strncmp(a->line, "CLT ", 4))
		a->tsprt.C = path_to_text(a, a->tsprt.dim_c, a->tsprt.c, &a->tsprt.sl_c);
	else
	{
		free(a->line);
		free_all(a, "ERROR2", 1);
	}
}

void	verif_pars(t_all *data)
{
	if(data->tmap.NO == NULL)
		free_all(data, "ERROR", 1);// verifier chemin
	else if(data->tmap.SO == NULL)
		free_all(data, "ERROR", 1);
	if(data->tmap.WE == NULL)
		free_all(data, "ERROR", 1);
	else if(data->tmap.EA == NULL)
		free_all(data, "ERROR", 1);
	if(data->tsprt.S == NULL)
		free_all(data, "ERROR", 1);
	else if(data->twdw.width < 0)
		free_all(data, "ERROR", 1);
	if(data->twdw.height < 0)
		free_all(data, "ERROR", 1);
	else if(data->tmap.F < 0)
		free_all(data, "ERROR", 1);
	else if(data->tmap.C < 0)
		free_all(data, "ERROR", 1);
}
