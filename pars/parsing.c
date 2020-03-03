/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:04:55 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/03 13:47:01 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*ft_strjoin_mark_free(char *s1, char *s2, char *mark)
{
	char	*x;
	char	*final;

	x = ft_strjoin(s1, mark);
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	final = ft_strjoin(x, s2);
	if (x)
	{
		free(x);
		x = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
	return (final);
}

static void	parsing_map(int fd, t_all *data, char *line_pars)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 1;
	tmp = line_pars;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		tmp = ft_strjoin_mark_free(tmp, line, "/");
	}
	if (line)
		free(line);
	data->tmap.map = ft_split(tmp, '/');
	free(tmp);
	if (close(fd) < 0)
		free_all(data, "file couldn't be closed ", 1);
	verifmap(data);
	//while(1);
}

static char *parsing_text(int fd, t_all *data)
{
	int	i;
	char *line;

	(void)data;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == '1')
			break;
		if (ft_strncmp(line, "\0", 1) != 0)
			for_parsing_text(data, line);
		free(line);
	}
	if (i == 0)
		free_all(data, "Error", 1);
	verif_pars(data);
	//while(1);
	return (line);
}	

void	parsing(char *file_name, t_all *data)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	//parsing_text(fd, data);
	/*printf("NO %s\n", data->tmap.NO);
	printf("%s\n", data->tmap.NO);
	printf("SO %s\n", data->tmap.SO);
	printf("WE %s\n", data->tmap.WE);
	printf("EA %s\n", data->tmap.EA);
	printf("S %s\n", data->tmap.S);
	printf("F %d\n", data->tmap.F);
	printf("C %d\n", data->tmap.C);
	printf("W %d\n", data->twdw.width);
	printf("H %d\n", data->twdw.height);*/
	parsing_map(fd, data, parsing_text(fd, data)); //parsing texture
}

