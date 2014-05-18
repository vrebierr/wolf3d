/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <vrebierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 17:48:56 by vrebierr          #+#    #+#             */
/*   Updated: 2014/05/18 17:48:57 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

static char	**tab_create(int y, int x)
{
	char	**tab;
	char	*tab2;
	int		i;

	tab = (char **)malloc(sizeof(char *) * x);
	tab2 = (char *)malloc(sizeof(char) * y * x);
	i = 0;
	while (i < y)
	{
		tab[i] = &tab2[i * x];
		i++;
	}
	return (tab);
}

char		**get_map(int fd)
{
	int		ret;
	char	**map;
	char	*line;
	int		j;
	int		i;

	ret = 1;
	i = 0;
	map = tab_create(24, 24);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			break ;
		j = 0;
		while (line[j])
		{
			map[i][j] = line[j];
			j++;
		}
		i++;
	}
	return (map);
}
