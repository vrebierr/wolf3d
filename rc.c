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

int				dist_to_wall(t_pos *pos)
{
	int		ay;
	int		ax;
	int		ray_x;
	int		ray_y;
	int		i;

	ray_x = pos->x;
	ray_y = pos->y;
	if (pos->rotation >= 0)
		ay = ray_x / 64 * 64 - 1;
	else
		ay = ray_x / 64 * 64 + 64;
	ax = ray_x + (ray_x - ay) / tan(FOV);
	ft_putnbr(ay / 64);
	i = 1;
	while (pos->map[ray_y / CUBE][ray_x / CUBE] != '0')
	{
		ray_y = ray_y + ay * i;
		ray_x = ray_x + ax * i;
		ft_putnbr(ray_x / 64);
		i++;
	}
	return (0);
}

void			raycasting(t_pos *pos, t_mlx *mlx)
{
	int		x;
	int		wall_dist;

	(void)mlx;
	x = 0;
	while (x < W)
	{
		wall_dist = dist_to_wall(pos);
		draw_line(CUBE / wall_dist * pos->dist_plane, x, mlx);
		x++;
	}
}
