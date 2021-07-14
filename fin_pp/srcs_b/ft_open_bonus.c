/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:52:31 by gejo              #+#    #+#             */
/*   Updated: 2021/07/03 18:54:52 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	ft_open(int idx, char **argv, char ***cmd_arr, int file1_fd)
{
	int		fd;

	if (idx == 1)
		fd = open(argv[idx], O_RDONLY);
	else
		fd = open(argv[idx], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		if (idx != 1)
			close(file1_fd);
		ft_error_fn(NULL, cmd_arr, NULL);
	}
	return (fd);
}
