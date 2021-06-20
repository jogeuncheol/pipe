/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 03:19:01 by gejo              #+#    #+#             */
/*   Updated: 2021/01/26 21:45:00 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_str(char const *s, char c)
{
	int i;
	int flag;
	int str;

	i = 0;
	flag = 0;
	str = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (flag == 0)
			{
				flag = 1;
				str++;
			}
		}
		else
			flag = 0;
		i++;
	}
	return (str);
}

char	**make_free(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

void	make_str(char const *s, char *ptr, int start, int end)
{
	int k;

	k = 0;
	while (start < end)
	{
		ptr[k] = s[start];
		k++;
		start++;
	}
	ptr[k] = '\0';
}

char	**make_split(char const *s, char c, char **ptr, int len)
{
	int i;
	int j;
	int word;
	int s_len;

	i = 0;
	j = 0;
	s_len = ft_strlen(s);
	while (i < len)
	{
		word = 0;
		while (s[j] == c && j < s_len)
			j++;
		while (s[j] != c && j < s_len)
		{
			word++;
			j++;
		}
		if (!(ptr[i] = (char *)malloc(sizeof(char) * (word + 1))))
			return (NULL);
		make_str(s, ptr[i], (j - word), j);
		i++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		len;

	if (s == NULL)
		return (NULL);
	len = check_str(s, c);
	if (!(ptr = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	if (!(make_split(s, c, ptr, len)))
	{
		make_free(ptr);
		free(ptr);
		ptr = 0;
		return (NULL);
	}
	ptr[len] = (NULL);
	return (ptr);
}
