/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:20:39 by ali               #+#    #+#             */
/*   Updated: 2021/07/07 17:19:50 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numstr(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static int	ft_strlenc(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_fill(char **strs, int size, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		while (*s && *s == c)
			s++;
		strs[i] = malloc((ft_strlenc(s, c) + 1) * sizeof(char));
		if (!strs[i])
			return (0);
		j = 0;
		while (*s && *s != c)
		{
			strs[i][j] = *s;
			s++;
			j++;
		}
		strs[i][j] = '\0';
		i++;
	}
	strs[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		size;

	if (s == NULL)
	{
		strs = malloc(sizeof(char *));
		if (!strs)
			return (NULL);
		strs[0] = NULL;
		return (strs);
	}
	size = ft_numstr(s, c);
	strs = malloc((size + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	if (!ft_fill(strs, size, s, c))
		return (NULL);
	return (strs);
}
