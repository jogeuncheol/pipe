/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 03:20:49 by gejo              #+#    #+#             */
/*   Updated: 2020/12/28 03:24:10 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *data;

	if (!(data = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	data->content = content;
	data->next = (NULL);
	return (data);
}
