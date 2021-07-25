/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 02:31:35 by gejo              #+#    #+#             */
/*   Updated: 2021/07/25 13:07:14 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_open(int idx, char **argv)
{
	int		fd;

	if (idx == 1)
		fd = open(argv[idx], O_RDONLY);
	else
		fd = open(argv[idx], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		perror(argv[idx]);
	return (fd);
}
