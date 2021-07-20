/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:38:59 by gejo              #+#    #+#             */
/*   Updated: 2020/12/30 18:55:44 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;
	size_t f_len;

	i = 0;
	f_len = 0;
	if (*to_find == '\0')
		return ((char *)str);
	if (str != NULL)
		f_len = ft_strlen(to_find);
	if (len < f_len)
		return (NULL);
	while (str[i] != '\0' && i <= (len - f_len))
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
