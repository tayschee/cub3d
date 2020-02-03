/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:48:38 by tbigot            #+#    #+#             */
/*   Updated: 2020/01/29 10:53:07 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ps;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else
		len -= start;
	if (!(ps = malloc(sizeof(*ps) * (len + 1))))
		return (0);
	i = 0;
	while (len-- > 0 && s[start + i])
	{
		ps[i] = s[start + i];
		i++;
	}
	ps[i] = '\0';
	return (ps);
}
