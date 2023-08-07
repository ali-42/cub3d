/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:32:17 by ali               #+#    #+#             */
/*   Updated: 2022/03/05 16:39:57 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_stock_line(char *stock)
{
	char	*line;
	int		i;

	if (!stock)
	{
		line = malloc(sizeof(char));
		if (!line)
			return (NULL);
		line[0] = '\0';
		return (line);
	}
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	ft_fill_rest(char *rest, char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		rest[i] = stock[i];
		i++;
	}
	rest[i] = '\0';
}

char	*ft_stock_rest(char *stock)
{
	char	*rest;
	int		i;

	if (!stock)
		return (NULL);
	if (!ft_strchr(stock, '\n'))
	{
		free(stock);
		return (NULL);
	}
	i = 0;
	while (stock[i] != '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(&stock[i]) + 1));
	if (!rest)
		return (NULL);
	i++;
	ft_fill_rest(rest, &stock[i]);
	free(stock);
	return (rest);
}

char	*join_buffer(char *buffer, char *stock)
{
	char	*tmp;

	tmp = ft_strjoin(stock, buffer);
	free(stock);
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	static char	*stock = NULL;
	char		buffer[4097];
	int			bytes;

	if (fd == -1 && stock)
	{
		free(stock);
		return (0);
	}
	if (!ft_strchr(stock, '\n'))
		bytes = read(fd, buffer, 4096);
	while (!ft_strchr(stock, '\n') && bytes)
	{
		if (bytes == -1)
			return (-1);
		buffer[bytes] = '\0';
		stock = join_buffer(buffer, stock);
		if (!ft_strchr(stock, '\n'))
			bytes = read(fd, buffer, 4096);
	}
	*line = ft_stock_line(stock);
	stock = ft_stock_rest(stock);
	if (!stock && !bytes)
		return (0);
	return (1);
}
