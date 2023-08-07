/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:24:42 by ali               #+#    #+#             */
/*   Updated: 2022/03/07 18:13:35 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_dir(t_player *player, char c)
{
	if (c == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	if (c == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	if (c == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	if (c == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
}

void	init_player(t_player *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == 'S')
			{
				player->map_x = j;
				player->map_y = i;
				player->pos_x = (double)j;
				player->pos_y = (double)i;
				init_dir(player, map[i][j]);
				get_plane(player, player->dir_x, player->dir_y);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_info(t_info *info, t_player *player, t_world *world)
{
	info->player = player;
	info->world = world;
	info->exit = 0;
	info->move_down = 0;
	info->move_up = 0;
	info->move_left = 0;
	info->move_right = 0;
	info->rotate_left = 0;
	info->rotate_right = 0;
}

int	main_loop(t_info *info)
{
	move(info);
	display_frame(info);
	return (0);
}

void	init_game(t_world *world)
{
	void		*mlx;
	void		*mlx_win;
	t_player	player[1];
	t_info		info[1];

	init_player(player, world->map);
	init_info(info, player, world);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "cub3d");
	info->mlx = mlx;
	info->mlx_win = mlx_win;
	get_all_textures(info);
	mlx_hook(mlx_win, 2, 1L << 0, key_press, info);
	mlx_hook(mlx_win, 3, 1L << 1, key_release, info);
	mlx_hook(mlx_win, 17, 1L << 5, close_game, info);
	mlx_loop_hook(mlx, main_loop, info);
	mlx_loop(mlx);
}
