/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 09:16:17 by ali               #+#    #+#             */
/*   Updated: 2022/03/07 00:07:22 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_cubfile(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i])
		return (0);
	i++;
	if (ft_strcmp(&str[i], "cub") != 0)
		return (0);
	return (1);
}

int	parsing(int ac, char **av, t_world *world)
{
	if (ac != 2)
	{
		ft_putendl_fd("Bad number of arguments", 2);
		ft_putendl_fd("Usage ./cub3d <map_file>.cub", 2);
		return (0);
	}
	if (!is_cubfile(av[1]))
	{
		ft_putendl_fd("The map file must have the .cub extension", 2);
		return (0);
	}
	if (!stock_map(av[1], world))
	{
		free_textures_path(world);
		return (0);
	}
	return (1);
}
