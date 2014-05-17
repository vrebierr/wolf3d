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
# define W 320
# define H 200
# define CUBE 64
# define FOV 60
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
	char		**map;
	int			x;
	int			y;
	int			rotation;
	int			dist_plane;
}				t_pos;

void			raycasting(t_pos *pos, t_mlx *mlx);

#endif
