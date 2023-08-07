/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:59:37 by ali               #+#    #+#             */
/*   Updated: 2021/07/07 17:12:46 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_fill(char *num, unsigned int nbr, int n, unsigned int div)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		num[i] = '-';
		i++;
	}
	while (div > 0)
	{
		num[i] = nbr / div + '0';
		nbr = nbr % div;
		div /= 10;
		i++;
	}
	num[i] = '\0';
}

char	*ft_itoa(int n)
{
	unsigned int	div;
	int				size;
	char			*num;
	unsigned int	nbr;

	if (n < 0)
		nbr = (unsigned int)(-n);
	else
		nbr = (unsigned int)n;
	div = 1;
	size = 1;
	while (div <= nbr / 10)
	{
		div *= 10;
		size++;
	}
	if (n < 0)
		size++;
	num = malloc((size + 1) * sizeof(char));
	if (!num)
		return (NULL);
	ft_fill(num, nbr, n, div);
	return (num);
}
