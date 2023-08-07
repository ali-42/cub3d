/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:47:55 by ali               #+#    #+#             */
/*   Updated: 2021/07/11 12:22:35 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (!new_ptr)
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (new_ptr);
	new_ptr = ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
