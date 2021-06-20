/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 03:17:52 by gejo              #+#    #+#             */
/*   Updated: 2020/12/28 03:28:37 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_ptr(char *ptr, int n, int len, int sign)
{
	int i;

	i = 0;
	if (n == -2147483648)
	{
		ptr[len - i] = -(n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (n < 0)
		n = n * -1;
	while (n / 10 != 0)
	{
		ptr[len - i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	ptr[len - i++] = (n % 10) + '0';
	if (sign == 1)
		ptr[i] = '\0';
	else
		ptr[i + 1] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		tmp;
	int		len;
	char	*ptr;

	len = 0;
	tmp = n;
	while ((tmp = tmp / 10) != 0)
		len++;
	len++;
	if (n < 0)
	{
		if (!(ptr = (char *)malloc(sizeof(char) * (len + 2))))
			return (NULL);
		ptr[0] = '-';
		return (make_ptr(ptr, n, len, -1));
	}
	else
	{
		if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		return (make_ptr(ptr, n, len - 1, 1));
	}
}
