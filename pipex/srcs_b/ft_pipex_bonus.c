/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 02:30:50 by gejo              #+#    #+#             */
/*   Updated: 2021/08/13 19:22:43 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_init_pipe(t_pipe *pip, char ***cmd_arr, int input_fd, char **argv)
{
	pip->input_fd = input_fd;
	pip->argv = argv;
//	pip->output_fd = output_fd;
	pip->cmd_idx = 0;
	pip->cmd_count = 0;
	while (cmd_arr[pip->cmd_count] != NULL)
		pip->cmd_count++;
}

void	ft_exec(t_pipe *pip, char ***cmd_arr, char **envp)
{
	if (cmd_arr[pip->cmd_idx + 1] == NULL)
	{
		ft_open_file(pip);
		if (pip->output_fd == -1)
			exit(1);
		close(pip->fd[1]);
	}
	if (execve(cmd_arr[pip->cmd_idx][0], cmd_arr[pip->cmd_idx], envp) == -1)
	{
		ft_putstr_fd(ft_print_cmd_name(cmd_arr[pip->cmd_idx][0]), 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(errno);
	}
}

void	ft_child(t_pipe *pip, char ***cmd_arr, char **envp)
{
	close(pip->fd[0]);
	if (cmd_arr[pip->cmd_idx + 1] != NULL)
	{
		dup2(pip->fd[1], 1);
		close(pip->fd[1]);
	}
	else
	{
		ft_open_file(pip);
		if (pip->output_fd == -1)
			exit(1);
		// dup2(pip->output_fd, 1);
		// close(pip->output_fd);
		close(pip->fd[1]);
	}
	if (pip->input_fd == -1 && pip->cmd_idx == 0)
		exit(errno);
	ft_exec(pip, cmd_arr, envp);
}

void	ft_parent(t_pipe *pip, pid_t pid)
{
	close(pip->fd[1]);
	waitpid(pid, NULL, WNOHANG);
	// if (pip->cmd_idx != pip->cmd_count - 1)
	dup2(pip->fd[0], 0);
	close(pip->fd[0]);
	pip->cmd_idx++;
}

void	ft_pipex(char ***cmd_arr, char **envp, int input_fd, char **argv)
{
	t_pipe	*pip;
	pid_t	pid;

	pip = malloc(sizeof(t_pipe));
	if (pip == NULL)
		ft_error(NULL, cmd_arr);
	ft_init_pipe(pip, cmd_arr, input_fd, argv);
	ft_open_file(pip);
	while (cmd_arr[pip->cmd_idx + 1] != NULL)
	{
		if (pipe(pip->fd) == -1)
			ft_error(NULL, cmd_arr);
		pid = fork();
		if (pid == 0)
			ft_child(pip, cmd_arr, envp);
		else if (pid > 0)
			ft_parent(pip, pid);
		else
			ft_error(NULL, cmd_arr);
	}
	while (wait(NULL) > 0)
		;
	ft_exec(pip, cmd_arr, envp);
	free(pip);
	pip = NULL;
	exit(0);
}
