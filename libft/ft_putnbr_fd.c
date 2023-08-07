/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:47:10 by ali               #+#    #+#             */
/*   Updated: 2020/11/16 12:56:26 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	div;
	unsigned int	nbr;
	char			c;

	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = (unsigned int)(-n);
	}
	else
		nbr = (unsigned int)n;
	div = 1;
	while (div <= nbr / 10)
		div *= 10;
	while (div > 0)
	{
		c = nbr / div + '0';
		write(fd, &c, 1);
		nbr = nbr % div;
		div /= 10;
	}
}
