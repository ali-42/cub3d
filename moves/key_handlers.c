/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:15:29 by ali               #+#    #+#             */
/*   Updated: 2022/03/07 17:35:09 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_info *info)
{
	destroy_textures(info);
	mlx_destroy_window(info->mlx, info->mlx_win);
	free_char2(info->world->map);
	mlx_destroy_display(info->mlx);
	free_textures_path(info->world);
	free(info->mlx);
	exit (0);
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		info->exit = 1;
	if (keycode == KEY_A)
		info->move_left = 1;
	if (keycode == KEY_W)
		info->move_up = 1;
	if (keycode == KEY_S)
		info->move_down = 1;
	if (keycode == KEY_D)
		info->move_right = 1;
	if (keycode == KEY_LEFT)
		info->rotate_left = 1;
	if (keycode == KEY_RIGHT)
		info->rotate_right = 1;
	return (0);
}

int	key_release(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		info->exit = 1;
	if (keycode == KEY_A)
		info->move_left = 0;
	if (keycode == KEY_W)
		info->move_up = 0;
	if (keycode == KEY_S)
		info->move_down = 0;
	if (keycode == KEY_D)
		info->move_right = 0;
	if (keycode == KEY_LEFT)
		info->rotate_left = 0;
	if (keycode == KEY_RIGHT)
		info->rotate_right = 0;
	return (0);
}
