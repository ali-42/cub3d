/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:02:47 by ali               #+#    #+#             */
/*   Updated: 2021/07/07 17:23:44 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_list	*ft_new(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = content;
	return (new);
}

static void	ft_push_back(t_list **lst, t_list *new)
{
	t_list	*begin;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	begin = (*lst);
	while (begin->next)
		begin = begin->next;
	begin->next = new;
	new->next = NULL;
}

static void	ft_lst_clear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->content)
			del(tmp->content);
		free(tmp);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newlist;

	if (!lst || !f)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		new = ft_new(f(lst->content));
		if (!new)
		{
			ft_lst_clear(&newlist, del);
			return (NULL);
		}
		ft_push_back(&newlist, new);
		lst = lst->next;
	}
	return (newlist);
}
