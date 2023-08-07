/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:08:52 by ali               #+#    #+#             */
/*   Updated: 2022/03/05 20:32:25 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_char(char c)
{
	if (c == ' ' || c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W')
		return (1);
	return (0);
}

int	check_line_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((i == 0 || !line[i + 1]) && line[i] != '1' && line[i] != ' ')
			return (0);
		if (line[i] != '1' && line[i] != ' ' && line[i + 1]
			&& line[i + 1] == ' ')
			return (0);
		if (line[i] == ' ' && line[i + 1] && line[i + 1] != '1'
			&& line[i + 1] != ' ')
			return (0);
		if (!is_valid_char(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	first_read_map(char *file, int fd, int *size, t_world *world)
{
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	while (ret)
	{
		if (ret == -1)
			return (perror_int(file));
		if (line[0] != '\0')
			size[0]++;
		if (line[0] && size[0] <= 6 && !stock_texture(line, world))
			return (format_error(file, line));
		if (line[0] && size[0] > 6 && ft_strlen(line) > size[1])
			size[1] = ft_strlen(line);
		if (line[0] && size[0] > 6 && !check_line_map(line))
			return (format_error(file, line));
		if (!line[0] && size[0] > 6)
			return (format_error(file, line));
		free(line);
		ret = get_next_line(fd, &line);
	}
	size[0] -= 6;
	free(line);
	return (1);
}

int	check_valid_map(char *file, char **map, int *size)
{
	int		i;
	int		j;
	int		player;

	player = 0;
	i = -1;
	while (++i < size[0])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((i == 0 || i == size[0] - 1) && map[i][j] != '1')
				return (format_error(file, NULL));
			if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
					|| map[i][j] == 'W') && player == 1)
				return (format_error(file, NULL));
			else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
					|| map[i][j] == 'W')
				player = 1;
		}
	}
	if (!player)
		return (format_error(file, NULL));
	return (1);
}

int	stock_map(char *to_open, t_world *world)
{
	int		fd;
	int		size[2];

	init_textures(world);
	fd = open(to_open, O_RDONLY);
	if (fd == -1)
		return (perror_int(to_open));
	size[0] = 0;
	size[1] = 0;
	if (!first_read_map(to_open, fd, size, world))
		return (close_map(fd, NULL));
	if (size[0] <= 2)
	{
		close(fd);
		return (format_error(to_open, NULL));
	}
	close(fd);
	fd = open(to_open, O_RDONLY);
	world->map = get_map(to_open, fd, size);
	if (!world->map)
		return (close_map(fd, NULL));
	if (!check_valid_map(to_open, world->map, size)
		|| !check_textures(to_open, world))
		return (close_map(fd, world->map));
	return (1);
}
