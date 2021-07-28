/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 02:30:50 by gejo              #+#    #+#             */
/*   Updated: 2021/07/28 16:16:18 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_init_pipe(t_pipe *pip, char ***cmd_arr, int file1_fd, int file2_fd)
{
	pip->backup_fd = file1_fd;
	pip->file2_fd = file2_fd;
	if (pip->backup_fd == -1)
		pip->cmd_idx = 1;
	else
		pip->cmd_idx = 0;
	pip->fd[0] = 0;
	pip->fd[1] = 0;
	pip->cmd_count = 0;
	while (cmd_arr[pip->cmd_count] != NULL)
		pip->cmd_count++;
}

void	ft_input_open_fail(t_pipe *pip, char ***cmd_arr)
{
	if (cmd_arr[pip->cmd_idx + 1] != NULL)
	{
		close(pip->fd[1]);
		close(pip->fd2[0]);
		dup2(pip->fd[0], 0);
		close(pip->fd[0]);
		dup2(pip->fd2[1], 1);
		close(pip->fd2[1]);
	}
	else
	{
		close(pip->fd[1]);
		dup2(pip->fd[0], 0);
		close(pip->fd[0]);
		dup2(pip->file2_fd, 1);
		close(pip->file2_fd);
	}
}

void	ft_child(t_pipe *pip, char ***cmd_arr, char **envp)
{
	if (pip->backup_fd == -1)
		ft_input_open_fail(pip, cmd_arr);
	else
	{
		close(pip->fd[0]);
		dup2(pip->backup_fd, 0);
		close(pip->backup_fd);
		if (cmd_arr[pip->cmd_idx + 1] != NULL)
		{
			dup2(pip->fd[1], 1);
			close(pip->fd[1]);
		}
		else
		{
			dup2(pip->file2_fd, 1);
			close(pip->fd[1]);
			close(pip->file2_fd);
		}
	}
	if (execve(cmd_arr[pip->cmd_idx][0], cmd_arr[pip->cmd_idx], envp) == -1)
	{
		ft_putstr_fd(ft_print_cmd_name(cmd_arr[pip->cmd_idx][0]), 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(errno);
	}
}

void	ft_parent(t_pipe *pip, pid_t pid)
{
	int		status;
	int		wpid;

	if (pip->backup_fd == -1 && pip->cmd_count > 2)
	{
		close(pip->fd[0]);
		close(pip->fd2[1]);
		close(pip->fd[1]);
	}
	else
		close(pip->fd[1]);
	while ((wpid = waitpid(pid, &status, WNOHANG)) == 0)
	{
		printf("wpid : %d\n", wpid);
		if (WIFSIGNALED(status))
			break ;
	}
	printf("wpid : %d\n", wpid);
	if (pip->backup_fd == -1 && pip->cmd_count > 2)
		pip->backup_fd = pip->fd2[0];
	else
		pip->backup_fd = pip->fd[0];
}

void	ft_pipex(char ***cmd_arr, char **envp, int file1_fd, int file2_fd)
{
	t_pipe	*pip;
	pid_t	pid;

	pip = malloc(sizeof(t_pipe));
	if (pip == NULL)
		ft_error(NULL, cmd_arr);
	ft_init_pipe(pip, cmd_arr, file1_fd, file2_fd);
	dup2(file1_fd, 0);
	while (cmd_arr[pip->cmd_idx] != NULL)
	{
		if (pipe(pip->fd) == -1)
			ft_error(NULL, cmd_arr);
		if (pip->backup_fd == -1 && pip->cmd_count > 2)
			pipe(pip->fd2);
		pid = fork();
		if (pid == 0)
		{
			//ft_child(pip, cmd_arr, envp);
			close(pip->fd[0]);
			if (cmd_arr[pip->cmd_idx + 1] != NULL)
			{
				dup2(pip->fd[1], 1);
				close(pip->fd[1]);
			}
			else
			{
				dup2(pip->file2_fd, 1);
				close(pip->file2_fd);
			}
			execve(cmd_arr[pip->cmd_idx][0], cmd_arr[pip->cmd_idx], envp);
		}
		else if (pid > 0)
		{
			//ft_parent(pip, pid);
			printf("fil1 %d file2 %d fd[0] %d fd[1] %d\n", file1_fd, file2_fd, pip->fd[0], pip->fd[1]);
			close(pip->fd[1]);
			dup2(pip->fd[0], 0);
			close(pip->fd[0]);
			waitpid(pid, NULL, WNOHANG);
		}
		else
			ft_error(NULL, cmd_arr);
		pip->cmd_idx++;
	}
	printf("ft_pipe fn end\n");
	int		status;
	int	wpid;
	while ((wpid = wait(&status)) > 0)
	{
		printf("wpid : %d\n", wpid);
		if (WIFSIGNALED(status))
		{
			printf("signaled %d\n", status);
			printf("WTERMSIG %d\n", WTERMSIG(status));
		}
	}
	free(pip);
	pip = NULL;
}