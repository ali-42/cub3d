/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:23:58 by ali               #+#    #+#             */
/*   Updated: 2022/03/07 00:10:23 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_charvalue(char *str)
{
	int	i;
	int	nb;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	nb = ft_atoi(str);
	if (nb > 255 || nb < 0)
		return (0);
	return (1);
}

int	get_color(int *color, char *str)
{
	char	**strs;
	int		i;

	strs = ft_split(str, ',');
	i = 0;
	while (strs[i])
	{
		if (!is_charvalue(strs[i]))
		{
			free_char2(strs);
			return (-1);
		}
		else if (i < 3)
			color[i] = ft_atoi(strs[i]);
		i++;
	}
	if (i != 3)
	{
		free_char2(strs);
		return (-1);
	}
	free_char2(strs);
	return (1);
}

int	retrieve_texture(char **strs, t_world *world)
{
	if (ft_strcmp(strs[0], "NO") == 0 && !world->no->path)
		world->no->path = ft_strdup(strs[1]);
	else if (ft_strcmp(strs[0], "SO") == 0 && !world->so->path)
		world->so->path = ft_strdup(strs[1]);
	else if (ft_strcmp(strs[0], "EA") == 0 && !world->ea->path)
		world->ea->path = ft_strdup(strs[1]);
	else if (ft_strcmp(strs[0], "WE") == 0 && !world->we->path)
		world->we->path = ft_strdup(strs[1]);
	else if (ft_strcmp(strs[0], "F") == 0)
		return (get_color(world->color_f, strs[1]));
	else if (ft_strcmp(strs[0], "C") == 0)
		return (get_color(world->color_c, strs[1]));
	else
		return (-1);
	return (1);
}

int	stock_texture(char *line, t_world *world)
{
	char	**strs;
	int		i;

	strs = ft_split(line, ' ');
	i = 0;
	while (strs[i])
		i++;
	if (i != 2)
	{
		free_char2(strs);
		return (0);
	}
	if (retrieve_texture(strs, world) == -1)
	{
		free_char2(strs);
		return (0);
	}
	free_char2(strs);
	return (1);
}
