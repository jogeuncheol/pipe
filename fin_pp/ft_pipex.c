#include "pipex.h"

void	init_pipe(t_pipe *pip, int file1_fd, int file2_fd)
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
		dup2(pip.file2_fd, 1);
	if (execve(cmd_arr[pip.cmd_idx][0], cmd_arr[pip.cmd_idx], envp) == -1)
		ft_error_fn(NULL, cmd_arr, NULL);
}

int		ft_pipex(char ***cmd_arr, char **envp, int file1_fd, int file2_fd)
{
	t_pipe	pip;
	pid_t	pid;

	init_pipe(&pip, file1_fd, file2_fd);
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
			close(file1_fd);
			close(file2_fd);
			ft_error_fn(NULL, cmd_arr, NULL);
		}
		pip.cmd_idx++;
	}
	return (0);
}