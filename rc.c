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

	while (map[pos->y ])
	if (pos->rotation > 0)
	{
<<<<<<< HEAD
		dda->map_x = ((int)ray->pos_x);
		dda->map_y = ((int)ray->pos_y);
		dda->delta_dist_x = sqrt(1 + (ray->dir_y * ray->dir_y)
								/ (ray->dir_x * ray->dir_x));
		dda->delta_dist_y = sqrt(1 + (ray->dir_x * ray->dir_x)
								/ (ray->dir_y * ray->dir_y));
		dda->hit = 0;
		dda = dda_init2(ray, dda);
=======
		y = ceil(pos->y / CUBE) * CUBE - 1;
		ya = - CUBE;
>>>>>>> master
	}
	else
	{
<<<<<<< HEAD
		if (dda->side_dist_x < dda->delta_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (map[dda->map_x][dda->map_y] > '0')
			dda->hit = 1;
=======
		y = ceil(pos->y / CUBE) * CUBE + 64;
		ya = CUBE;
>>>>>>> master
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
<<<<<<< HEAD
		ft_putnbr(x);
		ray.camera_x = 2 * x / (double)WIDTH;
		ray.pos_x = pos->pos_x;
		ray.pos_y = pos->pos_y;
		ray.dir_x = pos->dir_x + pos->plane_x * ray.camera_x;
		ray.dir_y = pos->dir_y + pos->plane_y * ray.camera_x;
		dda = dda_init(&ray);
		perform(dda, map, &ray);
		draw(dda, mlx, x);
=======
		dist_wall = get_dist_wall(pos, x);
		wall_h = CUBE / dist_wall * pos->dist_plane;
		draw_line(wall_h, x, mlx);
>>>>>>> master
		x++;
	}
}
