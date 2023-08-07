/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:42:30 by ali               #+#    #+#             */
/*   Updated: 2021/07/07 17:16:10 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;
	unsigned int	lensrc;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	lensrc = i;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = start;
	while (lensrc >= start && s[i] && i < len + start)
	{
		sub[i - start] = s[i];
		i++;
	}
	sub[i - start] = '\0';
	return (sub);
}
