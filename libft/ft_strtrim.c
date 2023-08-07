/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:10:41 by ali               #+#    #+#             */
/*   Updated: 2021/07/07 17:25:55 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_trimlen(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (*s1)
	{
		s1++;
		i++;
	}
	s1--;
	while (ft_is_set(*s1, set))
	{
		s1--;
		i--;
	}
	return (i);
}

static char	*ft_dupzero(void)
{
	char	*zero;

	zero = malloc(sizeof(char));
	if (!zero)
		return (NULL);
	zero[0] = '\0';
	return (zero);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed;
	int		i;
	int		len;

	if (s1 == NULL)
		return (NULL);
	while (*s1 && ft_is_set(*s1, set))
		s1++;
	if (*s1 == '\0')
		return (ft_dupzero());
	len = ft_trimlen(s1, set);
	trimed = malloc((len + 1) * sizeof(char));
	if (!trimed)
		return (NULL);
	i = 0;
	while (i < len)
	{
		trimed[i] = *s1;
		i++;
		s1++;
	}
	trimed[i] = '\0';
	return (trimed);
}
