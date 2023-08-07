/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:40:27 by ali               #+#    #+#             */
/*   Updated: 2022/03/05 20:16:56 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	format_error(char *str, char *line)
{
	if (line)
	{
		get_next_line(-1, NULL);
		free(line);
	}
	if (errno == EACCES)
		return (0);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": bad format", 2);
	return (0);
}

int	perror_int(char *str)
{
	ft_putendl_fd("Error", 2);
	perror(str);
	return (0);
}

void	*perror_ptr(char *str)
{
	ft_putendl_fd("Error", 2);
	perror(str);
	return (NULL);
}
