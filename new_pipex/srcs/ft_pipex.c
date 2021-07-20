#include "../include/pipex.h"

void	ft_init_pipe(t_pipe *pip, int file1_fd, int file2_fd)
{
	pip->cmd_idx = 0;
	pip->backup_fd = file1_fd;
	pip->file2_fd = file2_fd;
	pip->fd[0] = 0;
	pip->fd[1] = 0;
}

void	ft_child(t_pipe pip, char ***cmd_arr, char **envp)
{
	dup2(pip.backup_fd, 0);
	close(pip.backup_fd);
	if (cmd_arr[pip.cmd_idx + 1] != NULL)
	{
		dup2(pip.fd[1], 1);
		close(pip.fd[1]);
	}
	else
		dup(pip.file2_fd, 1);
	if (execve(cmd_arr[pip.cmd_idx][0], cmd_arr[pip.cmd_idx], envp) == -1)
		ft_error(NULL, cmd_arr);
}

void	ft_close_fd(int fd_0, int fd_1)
{
	close(fd_0);
	close(fd_1);
}

void	ft_pipex(char ***cmd_arr, char **envp, int file1_fd, int file2_fd)
{
	t_pipe	pip;
	pid_t	pid;

	ft_pipe(&pip, file1_fd, file2_fd);
	while (cmd_arr[pip.cmd_idx] != NULL)
	{
		pipe(pip.fd);
		pid = fork();
		if (pid == 0)
			ft_child(pip, cmd_arr, envp);
		else if (pid > 0)
		{
			wait(0);
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
