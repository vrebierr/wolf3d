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

static t_dda	*dda_init2(t_ray *ray, t_dda *dda)
{
	if (ray->dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (ray->pos_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - ray->pos_x) * dda->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (ray->pos_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - ray->pos_y) * dda->delta_dist_y;
	}
	return (dda);
}

static t_dda	*dda_init(t_ray *ray)
{
	t_dda	*dda;

	dda = (t_dda *)malloc(sizeof(t_dda));
	if (dda != NULL)
	{
		dda->map_x = (int)ray->pos_x;
		dda->map_y = (int)ray->pos_y;
		dda->delta_dist_x = sqrt(1 + (ray->dir_y * ray->dir_y)
								/ (ray->dir_x * ray->dir_x));
		dda->delta_dist_y = sqrt(1 + (ray->dir_x * ray->dir_x)
								/ (ray->dir_y * ray->dir_y));
		dda->hit = 0;
		dda = dda_init2(ray, dda);
	}
	return (dda);
}

static void		perform(t_dda *dda, t_pos *pos, t_ray *ray)
{
	while (dda->hit == 0)
	{
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
		if (pos->map[dda->map_x][dda->map_y] > '0')
			dda->hit = 1;
	}
	if (dda->side == 0)
		dda->perp_wall_dist = fabs((dda->map_x - ray->pos_x
									+ (1 - dda->step_x) / 2) / ray->dir_x);
	else
		dda->perp_wall_dist = fabs((dda->map_y - ray->pos_y
									+ (1 - dda->step_y) / 2) / ray->dir_y);
	if (dda->perp_wall_dist < 0.05)
		dda->perp_wall_dist = 0.05;
}

void			raycasting(t_pos *pos)
{
	int		x;
	t_ray	ray;
	t_dda	*dda;

	x = 0;
	while (x < WIDTH)
	{
		ray.camera_x = 2 * x / (double)WIDTH - 1;
		ray.pos_x = pos->pos_x;
		ray.pos_y = pos->pos_y;
		ray.dir_x = pos->dir_x + pos->plane_x * ray.camera_x;
		ray.dir_y = pos->dir_y + pos->plane_y * ray.camera_x;
		dda = dda_init(&ray);
		perform(dda, pos, &ray);
		draw(dda, pos->mlx, x);
		x++;
	}
}
