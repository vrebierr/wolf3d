/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <vrebierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 15:03:02 by vrebierr          #+#    #+#             */
/*   Updated: 2014/05/07 15:03:03 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

void			draw_line(int wall_h, int x, t_mlx *mlx)
{
	int		start;
	int		end;
	int		y;

	start = wall_h / 2 + H / 2;
	end = start + wall_h;
	y = 0;
	while (y < start)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 202020);
		y++;
	}
	while (y < end)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 808080);
		y++;
	}
	while (y < H)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 888888);
		y++;
	}
}

int				get_dist_wall(t_pos *pos, char **map)
{
	int		x;
	int		y;
	int		xa;
	int		ya;

	while (map[])
	if (pos->rotation > 0)
	{
		y = ceil(pos->y / CUBE) * CUBE - 1;
		ya = - CUBE;
	}
	else
	{
		y = ceil(pos->y / CUBE) * CUBE + 64;
		ya = CUBE;
	}
	x = pos->x + (pos->y - y) / tan(FOV);
	xa = CUBE / tan(FOV);
}

void			raycasting(t_pos *pos, char **map, t_mlx *mlx)
{
	int		x;
	int		wall_h;
	int		dist_wall;

	x = 0;
	while (x < W)
	{
		dist_wall = get_dist_wall(pos, x);
		wall_h = CUBE / dist_wall * pos->dist_plane;
		draw_line(wall_h, x, mlx);
		x++;
	}
}
