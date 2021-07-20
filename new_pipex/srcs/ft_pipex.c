#include "../include/pipex.h"

void	ft_init_pipe(t_pipe *pip, int file1_fd, int file2_fd)
{
	pip->cmd_idx = 0;
	if (file1_fd == -1)
		pip->cmd_idx++;
	pip->backup_fd = file1_fd;
	pip->file2_fd = file2_fd;
	pip->fd[0] = 0;
	pip->fd[1] = 0;
	pip->process_exit = 0;
}

void	ft_child(t_pipe pip, char ***cmd_arr, char **envp)
{
	if (pip.backup_fd == -1)
	{
		dup2(pip.fd[0], 0);
		close(pip.fd[0]);
	}
	else
	{
		dup2(pip.backup_fd, 0);
		close(pip.backup_fd);
		if (cmd_arr[pip.cmd_idx + 1] != NULL)
		{
			dup2(pip.fd[1], 1);
			close(pip.fd[1]);
		}
		else
			dup2(pip.file2_fd, 1);
	}
	if (execve(cmd_arr[pip.cmd_idx][0], cmd_arr[pip.cmd_idx], envp) == -1)
		exit(1);
}

void	ft_close_fd(int fd_0, int fd_1)
{
	close(fd_0);
	close(fd_1);
}

void	ft_parent(t_pipe pip, pid_t pid, int *status)
{
	waitpid(pid, status, WNOHANG);
	if (pip.backup_fd != -1)
		close(pip.fd[1]);
	pip.backup_fd = pip.fd[0];
}

void	ft_pipex(char ***cmd_arr, char **envp, int file1_fd, int file2_fd)
{
	t_pipe	pip;
	pid_t	pid;
	int		status;

	ft_init_pipe(&pip, file1_fd, file2_fd);
	while (cmd_arr[pip.cmd_idx] != NULL)
	{
		pipe(pip.fd);
		if (pip.backup_fd == -1)
			close(pip.fd[1]);
		pid = fork();
		if (pid == 0)
			ft_child(pip, cmd_arr, envp);
		else if (pid > 0)
		{
			waitpid(pid, &status, WNOHANG);
			if (pip.backup_fd != -1)
				close(pip.fd[1]);
			pip.backup_fd = pip.fd[0];
		}
		else
		{
			ft_close_fd(file1_fd, file2_fd);
			ft_close_fd(pip.fd[0], pip.fd[1]);
			ft_error(NULL, cmd_arr);
		}
		pip.cmd_idx++;
	}
}
