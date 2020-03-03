/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:14:07 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/03 11:03:09 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		verifchar(char c, char *valid)
{
	int	i;

	i = 0;
	while(valid[i])
	{
		if (c == valid[i])
			return(1);
		i++;
	}
	return(0);
}

static void	dimension_wdw(char *line, t_all *data)
{
	int i;

	i = 0;
	while (line[i] != ' ')
		i++;
	i++;
	data->twdw.width = ft_atoi(&line[i]);
	while(line[i] != ' ')
		i++;
	i++;
	data->twdw.height = ft_atoi(&line[i]);
}

static int		color(char	*line, t_all *data)
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

static char	*path_to_text(char *line)
{
	int i;

	i = 0;
	while (line[i] != ' ')
		i++;
	i++;
	return(ft_strdup(&line[i]));
}


void	for_parsing_text(t_all *data, char	*line)
{
	if(!ft_strncmp(line, "NO ", 3))
		data->tmap.NO = path_to_text(line);//probablement changer la text ne s'enregistre ppas comme ca	
	else if(!ft_strncmp(line, "SO ", 3))
		data->tmap.SO = path_to_text(line);
	else if(!ft_strncmp(line, "WE ", 3))
		data->tmap.WE = path_to_text(line);
	else if(!ft_strncmp(line, "EA ", 3))
		data->tmap.EA = path_to_text(line);
	else if(!ft_strncmp(line, "R ", 2))
		dimension_wdw(line, data); // inclure un int maxx et minpour la taille de la fenetre
	else if(!ft_strncmp(line, "S ", 2))
		data->tmap.S = path_to_text(line);
	else if(!ft_strncmp(line, "F ", 2))
		data->tmap.F = color(line, data);
	else if (!ft_strncmp(line, "C ", 2))
		data->tmap.C = color(line, data);
	else if (!ft_strncmp(line, "TRAP ", 5))
		data->tmap.T = path_to_text(line);
	else if (!ft_strncmp(line, "CLT ", 4))
		data->tmap.CLT = path_to_text(line);	
	else
	{
		free(line);
		free_all(data, "ERROR2", 1);
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
	if(data->tmap.S == NULL)
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
