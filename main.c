/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <vrebierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 11:49:23 by vrebierr          #+#    #+#             */
/*   Updated: 2014/05/06 11:49:24 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

void	show_error(char *msg)
{
	perror(msg);
	exit(1);
}

char	**tab_create(int y, int x)
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

char	**get_map(char *file)
{
	int		ret;
	char	**map;
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		show_error("open");
	ret = 1;
	map = tab_create(24, 24);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			break ;
		while (*line)
		{
			**map = *line;
			(**map)++;
			line++;
		}
		(*map)++;
	}
	return (map);
}

void	show_usage(void)
{
	ft_putstr("Usage: ./wolf3d my_map\n");
	exit(1);
}

int		expose_hook(void *param)
{
	(void)param;
	return (0);
}

int		key_hook(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	char	**map;

	if (argc != 2)
		show_usage();
	map = get_map(argv[1]);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Wolf3d");
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	raycasting(pos_init(), map, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
