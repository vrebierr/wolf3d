/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <vrebierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 18:04:40 by vrebierr          #+#    #+#             */
/*   Updated: 2014/05/08 18:04:41 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

void	draw(t_dda *dda, t_mlx *mlx, int x)
{
	int		height;
	int		start;
	int		end;

	height = abs((int)HEIGHT / (int)dda->perp_wall_dist);
	start = -height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	while (start < end)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, start, 200);
		start++;
	}
}
