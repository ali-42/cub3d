/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:59:15 by ali               #+#    #+#             */
/*   Updated: 2022/03/05 17:25:17 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*strdup_map_line(char *line, int width)
{
	char	*dup;
	int		i;

	if (!line)
		return (NULL);
	dup = malloc(sizeof(char) * (width + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			dup[i] = '1';
		else
			dup[i] = line[i];
		i++;
	}
	while (i < width)
	{
		dup[i] = '1';
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	get_map_line(int index, char *line, char **map, int width)
{
	int	i;

	if (index <= 6)
		return (1);
	i = index - 7;
	map[i] = strdup_map_line(line, width);
	if (!map[i])
	{
		get_next_line(-1, NULL);
		free(line);
		free_char2(map);
		return (0);
	}
	return (1);
}

char	**get_map(char *file, int fd, int *size)
{
	char	**map;
	char	*line;
	int		i;
	int		ret;

	map = malloc((size[0] + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	ret = get_next_line(fd, &line);
	i = 0;
	while (ret)
	{
		if (ret == -1)
			return (perror_ptr(file));
		if (line[0])
			i++;
		if (!get_map_line(i, line, map, size[1]))
			return (NULL);
		free(line);
		ret = get_next_line(fd, &line);
	}
	map[size[0]] = NULL;
	free(line);
	close(fd);
	return (map);
}
