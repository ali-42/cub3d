/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:46:52 by ali               #+#    #+#             */
/*   Updated: 2022/03/06 23:13:45 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_plane(t_player *player, double dir_x, double dir_y)
{
	player->plane_x = ANGLE * (cos(M_PI / 2) * dir_x - sin(M_PI / 2) * dir_y);
	player->plane_y = ANGLE * (sin(M_PI / 2) * dir_x + cos(M_PI / 2) * dir_y);
}

void	rotate_left(t_player *player)
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	dir_x = player->dir_x;
	dir_y = player->dir_y;
	plane_x = player->plane_x;
	plane_y = player->plane_y;
	player->dir_x = cos(-ROT_SPEED) * dir_x - sin(-ROT_SPEED) * dir_y;
	player->dir_y = sin(-ROT_SPEED) * dir_x + cos(-ROT_SPEED) * dir_y;
	player->plane_x = cos(-ROT_SPEED) * plane_x - sin(-ROT_SPEED) * plane_y;
	player->plane_y = sin(-ROT_SPEED) * plane_x + cos(-ROT_SPEED) * plane_y;
}

void	rotate_right(t_player *player)
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	dir_x = player->dir_x;
	dir_y = player->dir_y;
	plane_x = player->plane_x;
	plane_y = player->plane_y;
	player->dir_x = cos(ROT_SPEED) * dir_x - sin(ROT_SPEED) * dir_y;
	player->dir_y = sin(ROT_SPEED) * dir_x + cos(ROT_SPEED) * dir_y;
	player->plane_x = cos(ROT_SPEED) * plane_x - sin(ROT_SPEED) * plane_y;
	player->plane_y = sin(ROT_SPEED) * plane_x + cos(ROT_SPEED) * plane_y;
}
