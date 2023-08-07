/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:43:43 by ali               #+#    #+#             */
/*   Updated: 2022/03/07 15:30:44 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_world *world)
{
	world->no->path = NULL;
	world->no->img = NULL;
	world->so->path = NULL;
	world->so->img = NULL;
	world->we->path = NULL;
	world->we->img = NULL;
	world->ea->path = NULL;
	world->ea->img = NULL;
	world->color_f[0] = -1;
	world->color_c[0] = -1;
}

int	check_textures(char *file, t_world *world)
{
	if (!world->no->path || !world->so->path || !world->ea->path
		|| !world->we->path || world->color_f[0] == -1
		|| world->color_c[0] == -1)
	{
		format_error(file, NULL);
		return (0);
	}
	return (1);
}
