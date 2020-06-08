/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:14:07 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/05 18:25:21 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		dimension_wdw(char *line, t_all *data, int *width,
int *height)
{
	int		i;
	char	**txt;
	int n;

	i = 0;
	if (*width == -1)
	{
		mlx_get_screen_size(data->twdw.ptr, width, height);
		txt = ft_split(line, ' ');
		while (txt[i])
			i++;
		if (i == 3)
		{
			n = ft_atoi(txt[1]);
			*width = *width > n ? n : *width;
			*width = *width > n ? n : *width;
			n = ft_atoi(txt[2]);
			*height = *height > n ? n : *height;
			data->twdw.size_line = *width * 4;
		}
		free_malloc_2d(txt);
		if (*width >= 60 && *height >= 60)
			return ;
	}
	free(line);
	free_all(data, "ERROR\n", 1);
}

static void		color(char *line, t_all *data, int *nb)
{
	int		i;
	int		y;
	char	**tab;

	i = -1;
	tab = ft_split(line, ',');
	if (*nb != -1)
	{
		free(line);
		free_all(data, "ERROR\n", 1);
	}
	*nb = 0;
	while (tab && tab[++i])
	{
		if ((y = ft_atoi(tab[i])) > 255 || i > 2)
		{
			free_malloc_2d(tab);
			free_all(data, "ERROR\n", 1);
		}
		*nb = *nb << 8;
		*nb += y;
	}
	free_malloc_2d(tab);
	if (i < 2)
		free_all(data, "ERROR\n", 1);
}

static void		path_text(t_all *data, char **dir, char *line)
{
	char	**text;

	text = ft_split(data->line, ' ');
	if (*dir != NULL)
	{
		free(data->line);
		free_all(data, "ERROR\n", 1);
	}
	if (!(*dir = mlx_xpm_file_to_image(
	data->twdw.ptr, text[1], &data->twall.width, &data->twall.height)))
	{
		
	free_malloc_2d(text);
	ret = mlx_get_data_addr(*dir, &data->twdw.bpp, size_line, &data->twdw.end);
	dim[0] = data->twall.width;
	dim[1] = data->twall.height;
}

void			for_parsing_text(t_all *a)
{
	if (!ft_strncmp(a->line, "NO ", 3))
		/*a->tmap.noc =*/ path_text(a, &a->tmap.noc, a->line);
	else if (!ft_strncmp(a->line, "SO ", 3))
		/*a->tmap.soc =*/ path_text(a, &a->tmap.soc, a->line);
	else if (!ft_strncmp(a->line, "WE ", 3))
		/*a->tmap.wec =*/ path_text(a, &a->tmap.wec, a->line);
	else if (!ft_strncmp(a->line, "EA ", 3))
		/*a->tmap.eac =*/ path_text(a, &a->tmap.eac, a->line);
	else if (!ft_strncmp(a->line, "R ", 2))
	{
		dimension_wdw(a->line, a, &a->twdw.width, &a->twdw.height);
		if (!(a->tsprt.wray = malloc(sizeof(double) * a->twdw.width)))
			free_all(a, "ERROR\n", 1);
	}
	else if (!ft_strncmp(a->line, "F ", 2))
		color(&a->line[2], a, &a->tmap.fc);
	else if (!ft_strncmp(a->line, "C ", 2))
		color(&a->line[2], a, &a->tmap.cc);
	else if (!ft_strncmp(a->line, "S ", 2))
		/*a->tsprt.sc = */path_text(a, &a->tsprt.sc, a->line);
	else
	{
		free(a->line);
		free_all(a, "ERROR\n", 1);
	}
}

void			verif_pars(t_all *data)
{
	if (data->tmap.noc == NULL)
		free_all(data, "ERROR\n", 1);
	else if (data->tmap.soc == NULL)
		free_all(data, "ERROR\n", 1);
	if (data->tmap.wec == NULL)
		free_all(data, "ERROR\n", 1);
	else if (data->tmap.eac == NULL)
		free_all(data, "ERROR\n", 1);
	if (data->tsprt.sc == NULL)
		free_all(data, "ERROR\n", 1);
	else if (data->twdw.width < 0)
		free_all(data, "ERROR\n", 1);
	if (data->twdw.height < 0)
		free_all(data, "ERROR\n", 1);
	else if (data->tmap.fc < 0)
		free_all(data, "ERROR\n", 1);
	else if (data->tmap.cc < 0)
		free_all(data, "ERROR\n", 1);
}
