/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:34:54 by gejo              #+#    #+#             */
/*   Updated: 2020/12/30 19:27:19 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	i = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize == 0 || dstsize <= d_len)
		return (s_len + dstsize);
	else
	{
		while (i < (dstsize - d_len - 1) && *(src + i) != '\0')
		{
			*(dst + d_len + i) = *(src + i);
			i++;
		}
		*(dst + d_len + i) = '\0';
	}
	return (d_len + s_len);
}
