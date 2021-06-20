/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:34:19 by gejo              #+#    #+#             */
/*   Updated: 2020/12/23 19:44:02 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (*(s + i) != (unsigned char)c)
	{
		if (*(s + i) == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}
