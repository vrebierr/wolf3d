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

void	show_usage(void)
{
	ft_putstr("Usage: ./wolf3d my_map\n");
	exit(1);
}

int		loop_hook(t_pos *pos)
{
	if (pos->mlx->img->img)
	{
		mlx_destroy_image(pos->mlx->mlx, pos->mlx->img->img);
		pos->mlx->img->img = mlx_new_image(pos->mlx->mlx, WIDTH, HEIGHT);
	}
	raycasting(pos);
	mlx_put_image_to_window(pos->mlx->mlx, pos->mlx->win,
							pos->mlx->img->img, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_pos	*pos;
	char	**map;
	int		fd;

	if (argc != 2)
		show_usage();
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		show_error("open");
	map = get_map(fd);
	pos = pos_init(map);
	mlx_loop_hook(pos->mlx->mlx, loop_hook, pos);
	mlx_key_hook(pos->mlx->win, key_hook, pos);
	mlx_loop(pos->mlx->mlx);
	return (0);
}
