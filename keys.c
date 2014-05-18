/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <vrebierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 20:17:18 by vrebierr          #+#    #+#             */
/*   Updated: 2014/05/15 20:17:19 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

static void	key_up(t_pos *pos)
{
	int		tmp;

	tmp = (int)(pos->pos_x + pos->dir_x * 0.5);
	if (pos->map[tmp][(int)pos->pos_y] == '0')
		pos->pos_x += pos->dir_x * 0.5;
	tmp = (int)(pos->pos_y + pos->dir_y * 0.5);
	if (pos->map[(int)pos->pos_x][tmp] == '0')
		pos->pos_y += pos->dir_y * 0.5;
}

static void	key_down(t_pos *pos)
{
	int		tmp;

	tmp = (int)(pos->pos_x - pos->dir_x * 0.5);
	if (pos->map[tmp][(int)pos->pos_y] == '0')
		pos->pos_x -= pos->dir_x * 0.5;
	tmp = (int)(pos->pos_y - pos->dir_y * 0.5);
	if (pos->map[(int)pos->pos_x][tmp] == '0')
		pos->pos_y -= pos->dir_y * 0.5;
}

static void	key_left(t_pos *pos)
{
	double	old_dir;
	double	old_plane;

	old_dir = pos->dir_x;
	pos->dir_x = pos->dir_x * cos(0.5) - pos->dir_y * sin(0.5);
	pos->dir_y = old_dir * sin(0.5) + pos->dir_y * cos(0.5);
	old_plane = pos->plane_x;
	pos->plane_x = pos->plane_x * cos(0.5) - pos->plane_y * sin(0.5);
	pos->plane_y = old_plane * sin(0.5) + pos->plane_y * cos(0.5);
}

static void	key_right(t_pos *pos)
{
	double	old_dir;
	double	old_plane;

	old_dir = pos->dir_x;
	pos->dir_x = pos->dir_x * cos(-0.5) - pos->dir_y * sin(-0.5);
	pos->dir_y = old_dir * sin(-0.5) + pos->dir_y * cos(-0.5);
	old_plane = pos->plane_x;
	pos->plane_x = pos->plane_x * cos(-0.5) - pos->plane_y * sin(-0.5);
	pos->plane_y = old_plane * sin(-0.5) + pos->plane_y * cos(-0.5);
}

int			key_hook(int keycode, t_pos *pos)
{
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
