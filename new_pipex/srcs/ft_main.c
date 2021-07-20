#include "../include/pipex.h"

int	ft_count_cmd(char **argv)
{
	int		i;
	int		count;

	i = 2;
	count = 0;
	while (argv[i + 1] != NULL)
	{
		if (argv[i][0] == '-')
			i++;
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}

int	ft_find_path_idx(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = "PATH=";
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], path, 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_setting_cmd(char **cmd_path, int argc, char **argv, char **envp)
{
	char	***cmd_arr;
	int		file1_fd;
	int		file2_fd;

	cnd_arr = ft_set_cmd_arr(cmd_path, argv, 0);
	if (cmd_arr == NULL)
		ft_error(cmd_path, cmd_arr);
	file1_fd = ft_open(1, argv, cmd_arr, 0);
	file2_fd = ft_open(argv - 1, argv, cmd_arr, file1_fd);
	free_cmd_path(cmd_path);
	ft_pipex(cmd_arr, envp, file1_fd, file2_fd);
	close(file1_fd);
	close(file2_fd);
	free_cmd_arr(cmd_arr);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**cmd_path;

	cmd_path = NULL;
	if (argc > 3 && count_cmd(argv) >= 2)
	{
		if (access(argv[1], F_OK) == -1)
			ft_error(NULL, NULL);
		else
		{
			cmd_path = ft_set_path(cmd_path, envp, find_path_idx(envp));
			if (cmd_path == NULL)
				ft_error(NULL, NULL);
			ft_setting_cmd(cmd_path, argc, argv, envp);
		}
	}
	else
	{
		ft_putstr_fd("Usage : ./pipex input_file cmd1 cmd2 output_file", 2);
		return (2);
	}
	return (0);
}