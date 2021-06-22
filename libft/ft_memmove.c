/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:33:46 by gejo              #+#    #+#             */
/*   Updated: 2020/12/30 20:32:23 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*s1;
	unsigned const char *s2;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned const char *)src;
	if ((dst == src) || (len == 0))
		return (dst);
	while (i < len)
	{
		if (s1 < s2)
			*(s1 + i) = *(s2 + i);
		else
			*(s1 + len - 1 - i) = *(s2 + len - 1 - i);
		i++;
	}
	return (dst);
}
