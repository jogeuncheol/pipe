#include "pipex.h"

void	init_pipe(t_pipe *pip, int file1_fd, int file2_fd)
{
	pip->cmd_idx = 0;
	pip->backup_fd = file1_fd;
	pip->file2_fd = file2_fd;
	pip->fd[0] = 0;
	pip->fd[1] = 0;
}

int		ft_child(t_pipe pip, char ***cmd_arr, char **envp)
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
	{
		perror(strerror(errno));
		return (-1);
	}
	return (0);
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
		{
			if (ft_child(pip, cmd_arr, envp) == -1)
				return (0);
		}
		else if (pid > 0)
		{
			wait(0);
			close(pip.fd[1]);
			pip.backup_fd = pip.fd[0];
		}
		else
			return (-1);
		pip.cmd_idx++;
	}
	return (0);
}