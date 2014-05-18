/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <vrebierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 17:46:44 by vrebierr          #+#    #+#             */
/*   Updated: 2014/05/18 17:46:47 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

t_mlx			*ft_mlx_init(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (mlx != NULL)
	{
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Wolf3d");
		mlx->img = (t_img *)malloc(sizeof(t_img));
		if (mlx->img != NULL)
		{
			mlx->img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
			mlx->img->data = mlx_get_data_addr(mlx->img->img, &(mlx->img->bpp),
									&(mlx->img->sizeline), &(mlx->img->endian));
		}
	}
	return (mlx);
}

t_pos			*pos_init(char **map)
{
	t_pos	*pos;

	pos = (t_pos *)malloc(sizeof(t_pos));
	if (pos != NULL)
	{
		pos->map = map;
		pos->pos_x = 2;
		pos->pos_y = 2;
		pos->dir_x = -1;
		pos->dir_y = 0;
		pos->plane_x = 0;
		pos->plane_y = 0.66;
		pos->mlx = ft_mlx_init();
	}
	return (pos);
}
