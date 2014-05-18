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

void	pixel_put_to_image(t_mlx *mlx, int x, int y, int color)
{
	t_img	*img;

	img = mlx->img;
	if (!mlx->img->endian)
	{
		img->data[(y * img->sizeline) + x * (img->bpp / 8)] = color;
		img->data[(y * img->sizeline) + x * (img->bpp / 8) + 1] = 0;
		img->data[(y * img->sizeline) + x * (img->bpp / 8) + 2] = 0;
	}
	else
	{
		img->data[(y * img->sizeline) + x * (img->bpp / 8)] = color;
		img->data[(y * img->sizeline) + x * (img->bpp / 8) + 1] = 0;
		img->data[(y * img->sizeline) + x * (img->bpp / 8) + 2] = 0;
	}
}

void	draw(t_dda *dda, t_mlx *mlx, int x)
{
	int		height;
	int		start;
	int		end;

	height = abs(HEIGHT / dda->perp_wall_dist);
	start = -height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	while (start < end)
	{
		pixel_put_to_image(mlx, x, start, 255);
		start++;
	}
}
