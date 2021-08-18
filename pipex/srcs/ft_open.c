/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 02:31:35 by gejo              #+#    #+#             */
/*   Updated: 2021/08/18 19:27:42 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_open(int idx, char **argv)
{
	int		fd;

	if (idx == 1)
		fd = open(argv[idx], O_RDONLY);
	else
	{
		while (argv[idx + 1] != NULL)
			idx++;
		fd = open(argv[idx], O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
	if (fd == -1)
		perror(argv[idx]);
	return (fd);
}

void	ft_open_file(t_pipe *pip)
{
	if (pip->cmd_idx == 0)
	{
		pip->input_fd = ft_open(1, pip->argv);
		if (dup2(pip->input_fd, 0) != -1)
			close(pip->input_fd);
	}
	else
	{
		pip->output_fd = ft_open(0, pip->argv);
		if (dup2(pip->output_fd, 1) != -1)
			close(pip->output_fd);
	}
}