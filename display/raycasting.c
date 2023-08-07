/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:05:38 by ali               #+#    #+#             */
/*   Updated: 2022/03/07 15:20:09 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_next(t_player *player, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->next_x = (player->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->next_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->next_y = (player->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->next_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_y;
	}
}

void	init_ray(t_player *player, t_ray *ray, int ray_num)
{
	double	camera_plane_x;

	camera_plane_x = ((2 * ray_num) / (double)WIDTH) - 1;
	ray->map_x = player->map_x;
	ray->map_y = player->map_y;
	ray->dir_x = player->dir_x + player->plane_x * camera_plane_x;
	ray->dir_y = player->dir_y + player->plane_y * camera_plane_x;
	if (ray->dir_x != 0)
		ray->delta_x = fabs(1 / ray->dir_x);
	else
		ray->delta_x = pow(10, 35);
	if (ray->dir_y != 0)
		ray->delta_y = fabs(1 / ray->dir_y);
	else
		ray->delta_y = pow(10, 35);
	init_ray_next(player, ray);
}	

double	ray_cast(t_ray *ray, char **map, int *side)
{
	int		hit_wall;

	hit_wall = 0;
	while (hit_wall == 0)
	{
		if (ray->next_x < ray->next_y)
		{
			ray->next_x += ray->delta_x;
			ray->map_x += ray->step_x;
			*side = 0;
		}
		else
		{
			ray->next_y += ray->delta_y;
			ray->map_y += ray->step_y;
			*side = 1;
		}
		if (map[ray->map_y][ray->map_x] == '1')
			hit_wall = 1;
	}
	if (*side == 0)
		return (ray->next_x - ray->delta_x);
	return (ray->next_y - ray->delta_y);
}

void	get_walls(t_player *player, char **map, t_wall *wall)
{
	int		i;
	int		side[1];
	t_ray	ray[1];

	i = 0;
	while (i < WIDTH)
	{
		init_ray(player, ray, i);
		wall[i].dist = ray_cast(ray, map, side);
		get_precise_hit(player, &wall[i], ray, side);
		if (*side == 0 && ray->step_x == 1)
			wall[i].texture = 'E';
		if (*side == 0 && ray->step_x == -1)
			wall[i].texture = 'W';
		if (*side == 1 && ray->step_y == 1)
			wall[i].texture = 'S';
		if (*side == 1 && ray->step_y == -1)
			wall[i].texture = 'N';
		i++;
	}
}
