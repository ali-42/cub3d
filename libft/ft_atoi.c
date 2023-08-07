/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:37:16 by ali               #+#    #+#             */
/*   Updated: 2021/07/07 17:31:45 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*nptr == '\t' || *nptr == '\v' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\f' || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr <= '9' && *nptr >= '0')
	{
		num = 10 * num + *nptr - '0';
		nptr++;
	}
	return (sign * num);
}
