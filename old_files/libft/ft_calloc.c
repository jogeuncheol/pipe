/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:44:11 by gejo              #+#    #+#             */
/*   Updated: 2020/12/28 19:45:10 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void *ptr;

	ptr = malloc(num * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, num * size);
	return (ptr);
}
