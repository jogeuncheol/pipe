/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:11:20 by gejo              #+#    #+#             */
/*   Updated: 2020/12/30 19:22:01 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_set(char const *set, char s1)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

int		check_start_end(char const *s1, char const *set, int index)
{
	int i;

	i = 0;
	if (index == 0)
	{
		while (s1[i])
		{
			if (check_set(set, s1[i]))
				i++;
			else
				break ;
		}
		return (i);
	}
	else
	{
		while (s1[index - i])
		{
			if (check_set(set, s1[index - i]))
				i++;
			else
				break ;
		}
		return (i);
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	start;
	char	*ptr;

	i = 0;
	len = 0;
	start = 0;
	if (s1 == NULL || set == NULL)
		return ((s1 != NULL) ? ft_strdup(s1) : (NULL));
	len = ft_strlen(s1);
	start = check_start_end(s1, set, 0);
	if (start == len)
		return (ft_strdup(""));
	len = len - check_start_end(s1, set, len - 1);
	if (!(ptr = (char *)malloc(sizeof(char) * (len - start + 1))))
		return (NULL);
	while (start < len)
	{
		ptr[i] = s1[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
