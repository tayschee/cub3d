/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_ok?.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:17:19 by tbigot            #+#    #+#             */
/*   Updated: 2020/01/10 16:21:37 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <libc.h>

int check_c(char c, char *accept_c)
{
	while (*accept_c)
	{
		if (c == *accept_c)
			return (0);
		accept_c++;
	}
	return (1);
}
int check_o(char *line, char *c_accept)
{
	int count;
	int i;

	i = -1;
	count = 0;
	while (line[++i])
	{
		if (check_c(line[i], c_accept) && line[i] != 32)
		{
			if (line)
				free(line);
			perror("invalid map 1");
			exit(1);
		}
		if (line[i] != 32)
			count++;
	}
	if (line)
		free(line);
	return (count);
}


void	check_map(char *input, int screen)
{
	char *line;
	int fd;
	int i;
	int size;

	(void)screen;
	if (-1 == (fd = open(input, O_RDONLY)))
		perror("open failed");
	//other_argument(fd, line);
	i = get_next_line(fd, &line);
	size = check_o(line, "1");
	while ((i = get_next_line(fd, &line)) > 0)
	{
		if (size != check_o(line, "012NSEW"))
		{
			perror("invalid map 2");
			exit(1);
		}
	}
	if (-1 == close(fd))
	{
		perror("close failed");
		exit (1);
	}
	//else
	//	open_window(fd, screen);
	exit(0);
	
}
