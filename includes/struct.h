/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:39:08 by ali               #+#    #+#             */
/*   Updated: 2022/03/07 16:01:34 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_texture
{
	char	*path;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}			t_texture;

typedef struct s_world
{
	char		**map;
	t_texture	no[1];
	t_texture	so[1];
	t_texture	ea[1];
	t_texture	we[1];
	int			color_f[3];
	int			color_c[3];
}				t_world;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
}				t_player;

typedef struct s_ray
{
	double	next_x;
	double	next_y;
	double	delta_x;
	double	delta_y;
	double	dir_x;
	double	dir_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
}				t_ray;

typedef struct s_wall
{
	double	dist;
	char	texture;
	int		height;
	int		begin;
	int		end;
	double	hit_x;
	int		neg_hit;
}				t_wall;

typedef struct s_info
{
	t_world		*world;
	t_player	*player;
	int			exit;
	int			move_left;
	int			move_right;
	int			move_up;
	int			move_down;
	int			rotate_left;
	int			rotate_right;
	void		*mlx;
	void		*mlx_win;
	void		*frame;
	void		**textures;
}				t_info;

typedef struct s_frame
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_frame;

#endif
