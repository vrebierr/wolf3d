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
	int		i;
	int		j;

	if ((fd = open(file, O_RDONLY)) == -1)
		perror("open");
	ret = 1;
	map = tab_create(24, 24);
	i = 0;
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
	if (keycode == UP)
		key_up();
	else if (keycode == DOWN)
		key_down();
	else if (keycode == LEFT)
		key_left();
	else if (keycode == RIGHT)
		key_right();
	return (0);
}

t_pos	*pos_init(void)
{
	t_pos	*pos;

	pos = (t_pos *)malloc(sizeof(t_pos));
	if (pos != NULL)
	{
		pos->x = 22;
		pos->y = 21;
		pos->rotation = 0;
		pos->dist_plane = (H / 2) / tan(FOV / 2);
	}
	return (pos);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	char	**map;
	t_pos	*pos;

	if (argc != 2)
		show_usage();
	map = get_map(argv[1]);
	pos = pos_init();
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, W, H, "Wolf3d");
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	raycasting(pos, map, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
