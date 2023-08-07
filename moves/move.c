/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:19:33 by ali               #+#    #+#             */
/*   Updated: 2022/03/07 17:18:59 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_down(t_player *player, char **map)
{
	double	target_y;
	double	target_x;

	target_x = player->pos_x - player->dir_x * MOV_SPEED;
	target_y = player->pos_y - player->dir_y * MOV_SPEED;
	if (map[(int)player->pos_y][(int)target_x] != '1')
		player->pos_x = target_x;
	if (map[(int)target_y][(int)player->pos_x] != '1')
		player->pos_y = target_y;
}

void	move_up(t_player *player, char **map)
{
	double	target_y;
	double	target_x;

	target_x = player->pos_x + player->dir_x * MOV_SPEED;
	target_y = player->pos_y + player->dir_y * MOV_SPEED;
	if (map[(int)player->pos_y][(int)target_x] != '1')
		player->pos_x = target_x;
	if (map[(int)target_y][(int)player->pos_x] != '1')
		player->pos_y = target_y;
}

void	move_left(t_player *player, char **map)
{
	double	target_y;
	double	target_x;
	double	lateral_dir_x;
	double	lateral_dir_y;

	lateral_dir_x = cos(-M_PI / 2) * player->dir_x
		- sin(-M_PI / 2) * player->dir_y;
	lateral_dir_y = sin(-M_PI / 2) * player->dir_x
		+ cos(-M_PI / 2) * player->dir_y;
	target_x = player->pos_x + lateral_dir_x * MOV_SPEED / 2;
	target_y = player->pos_y + lateral_dir_y * MOV_SPEED / 2;
	if (map[(int)player->pos_y][(int)target_x] != '1')
		player->pos_x = target_x;
	if (map[(int)target_y][(int)player->pos_x] != '1')
		player->pos_y = target_y;
}

void	move_right(t_player *player, char **map)
{
	double	target_y;
	double	target_x;
	double	lateral_dir_x;
	double	lateral_dir_y;

	lateral_dir_x = cos(-M_PI / 2) * player->dir_x
		- sin(-M_PI / 2) * player->dir_y;
	lateral_dir_y = sin(-M_PI / 2) * player->dir_x
		+ cos(-M_PI / 2) * player->dir_y;
	target_x = player->pos_x - lateral_dir_x * MOV_SPEED / 2;
	target_y = player->pos_y - lateral_dir_y * MOV_SPEED / 2;
	if (map[(int)player->pos_y][(int)target_x] != '1')
		player->pos_x = target_x;
	if (map[(int)target_y][(int)player->pos_x] != '1')
		player->pos_y = target_y;
}

void	move(t_info *info)
{
	if (info->exit)
		close_game(info);
	if (info->move_down)
		move_down(info->player, info->world->map);
	if (info->move_up)
		move_up(info->player, info->world->map);
	if (info->move_left)
		move_left(info->player, info->world->map);
	if (info->move_right)
		move_right(info->player, info->world->map);
	if (info->rotate_left)
		rotate_left(info->player);
	if (info->rotate_right)
		rotate_right(info->player);
	info->player->map_x = (int)info->player->pos_x;
	info->player->map_y = (int)info->player->pos_y;
}
