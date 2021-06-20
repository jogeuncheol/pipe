/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:19:42 by gejo              #+#    #+#             */
/*   Updated: 2020/12/28 04:23:20 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[len] != '\0')
		len++;
	while (*(s + len - i) != (unsigned char)c)
	{
		if (len == i)
			return (NULL);
		i++;
	}
	return ((char *)s + len - i);
}
