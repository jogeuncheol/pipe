/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:43:18 by gejo              #+#    #+#             */
/*   Updated: 2020/12/23 22:48:07 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\t' ||
			c == '\f' || c == '\r')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int		sign;
	size_t	result;

	sign = 1;
	result = 0;
	while (ft_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	if (result > 9223372036854775807)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (result * sign);
}
