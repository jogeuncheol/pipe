/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 02:31:35 by gejo              #+#    #+#             */
/*   Updated: 2021/07/21 02:31:38 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_open(int idx, char **argv, char ***cmd_arr, int file1_fd)
{
	int		fd;

	if (idx == 1)
		fd = open(argv[idx], O_RDONLY);
	else
		fd = open(argv[idx], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_putstr_fd("No such file or directory\n", 2);
	return (fd);
}
