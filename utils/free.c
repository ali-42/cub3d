/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:20:19 by ali               #+#    #+#             */
/*   Updated: 2022/03/07 15:30:55 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_char2(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	close_map(int fd, char **map)
{
	if (map)
		free_char2(map);
	close(fd);
	return (0);
}

void	free_textures_path(t_world *world)
{
	if (world->no->path)
		free(world->no->path);
	if (world->so->path)
		free(world->so->path);
	if (world->ea->path)
		free(world->ea->path);
	if (world->we->path)
		free(world->we->path);
}

void	destroy_textures(t_info *info)
{
	if (info->world->no->img)
		mlx_destroy_image(info->mlx, info->world->no->img);
	if (info->world->so->img)
		mlx_destroy_image(info->mlx, info->world->so->img);
	if (info->world->ea->img)
		mlx_destroy_image(info->mlx, info->world->ea->img);
	if (info->world->we->img)
		mlx_destroy_image(info->mlx, info->world->we->img);
}
