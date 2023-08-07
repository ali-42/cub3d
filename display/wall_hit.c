/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:22:57 by ali               #+#    #+#             */
/*   Updated: 2022/03/07 16:01:58 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_precise_hit(t_player *player, t_wall *wall, t_ray *ray, int *side)
{
	wall->neg_hit = 0;
	if (*side == 0)
	{
		wall->hit_x = player->pos_y + wall->dist * ray->dir_y;
		if (ray->dir_x > 0)
			wall->neg_hit = 1;
	}
	else
	{
		wall->hit_x = player->pos_x + wall->dist * ray->dir_x;
		if (ray->dir_y < 0)
			wall->neg_hit = 1;
	}
	wall->hit_x -= (int)wall->hit_x;
}
