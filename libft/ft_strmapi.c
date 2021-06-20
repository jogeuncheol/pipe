/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 03:19:12 by gejo              #+#    #+#             */
/*   Updated: 2020/12/30 19:25:02 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	len;
	unsigned int	i;
	unsigned int	ui;

	i = 0;
	ui = 0;
	if (s == NULL || f == NULL)
		return ((s == NULL) ? (NULL) : ft_strdup(s));
	len = ft_strlen((char *)s);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		ptr[i] = f(ui, s[i]);
		ui++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
