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
# define WIDTH 500
# define HEIGHT 500
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define ESCAPE 65307
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <libft.h>

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_mlx;

typedef struct	s_ray
{
	double		camera_x;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
}				t_ray;

typedef struct	s_pos
{
	char		**map;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	t_mlx		*mlx;
}				t_pos;

typedef struct	s_dda
{
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
}				t_dda;

t_pos			*pos_init(char **map);
void			raycasting(t_pos *pos);
void			draw(t_dda *dda, t_mlx *mlx, int x);
void			key_up(t_pos *pos);
void			key_down(t_pos *pos);
void			key_left(t_pos *pos);
void			key_right(t_pos *pos);

#endif
