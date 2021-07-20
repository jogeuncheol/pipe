/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 03:20:39 by gejo              #+#    #+#             */
/*   Updated: 2020/12/30 18:49:05 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_lst;
	t_list *head_lst;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(head_lst = ft_lstnew(lst->content)))
		return (NULL);
	head_lst->content = f(lst->content);
	lst = lst->next;
	while (lst != NULL)
	{
		if (!(new_lst = ft_lstnew(lst->content)))
		{
			ft_lstclear(&head_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&head_lst, new_lst);
		new_lst->content = f(lst->content);
		lst = lst->next;
	}
	return (head_lst);
}
