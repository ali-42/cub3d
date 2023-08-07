/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:39:39 by ali               #+#    #+#             */
/*   Updated: 2021/07/07 17:30:08 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (ptr1 && ptr2 && i < n && *ptr1 == *ptr2)
	{
		ptr1++;
		ptr2++;
		i++;
	}
	if (i == n)
		return (0);
	return (*ptr1 - *ptr2);
}
