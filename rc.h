/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <vrebierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 11:54:17 by vrebierr          #+#    #+#             */
/*   Updated: 2014/05/06 11:54:18 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RC_H
# define RC_H
<<<<<<< HEAD
# define WIDTH 500
# define HEIGHT 500
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define ESCAPE 65307
=======
# define W 320
# define H 200
# define CUBE 64
# define FOV 60
>>>>>>> master
# include <mlx.h>
# include <math.h>
# include <libft.h>

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_pos
{
	double		x;
	double		y;
	int			rotation;
	int			dist_plane;
}				t_pos;

void			raycasting(t_pos *pos, char **map, t_mlx *mlx);

#endif
