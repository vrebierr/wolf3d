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
	int		i;
	int		j;

	if ((fd = open(file, O_RDONLY)) == -1)
		show_error("open");
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

int		loop_hook(t_pos *pos)
{
	if (pos->mlx->img)
		mlx_destroy_image(pos->mlx->mlx, pos->mlx->img);
	raycasting(pos);
	mlx_put_image_to_window(pos->mlx->mlx, pos->mlx->win, pos->mlx->img, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_pos *pos)
{
	printf("dir_x = %f dir_y = %f plane_x = %f plane_y = %f\n", pos->dir_x,
		   pos->dir_y, pos->plane_x, pos->plane_y);
	if (keycode == UP)
		key_up(pos);
	else if (keycode == DOWN)
		key_down(pos);
	else if (keycode == LEFT)
		key_left(pos);
	else if (keycode == RIGHT)
		key_right(pos);
	else if (keycode == ESCAPE)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_pos	*pos;
	char	**map;

	if (argc != 2)
		show_usage();
	map = get_map(argv[1]);
	pos = pos_init(map);
	mlx_loop_hook(pos->mlx, loop_hook, pos);
	mlx_key_hook(pos->mlx->win, key_hook, pos);
	mlx_loop(pos->mlx->mlx);
	return (0);
}
