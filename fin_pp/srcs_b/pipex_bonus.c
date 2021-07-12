/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:51:38 by gejo              #+#    #+#             */
/*   Updated: 2021/07/03 18:55:57 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int		count_cmd(char **argv)
{
	int i;
	int count;

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

int		find_path_idx(char **envp)
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

void	setting_cmd(char **cmd_path, int argc, char **argv, char **envp)
{
	char	***cmd_arr;
	int		file1_fd;
	int		file2_fd;

	if (valid_argv(cmd_path, argv) == 1)
	{
		cmd_arr = set_cmd_arr(cmd_path, argv, 0);
		if (cmd_arr == NULL)
			ft_error_fn(cmd_path, cmd_arr, NULL);
		free_cmd_path(cmd_path);
		file1_fd = ft_open(1, argv, cmd_arr, 0);
		file2_fd = ft_open(argc - 1, argv, cmd_arr, file1_fd);
		ft_pipex(cmd_arr, envp, file1_fd, file2_fd);
		close(file1_fd);
		close(file2_fd);
		free_cmd_arr(cmd_arr);
	}
	else
		ft_error_fn(cmd_path, NULL, NULL);
}

int		main(int argc, char *argv[], char *envp[])
{
	char	**cmd_path;

	cmd_path = NULL;
	if (argc > 3 && count_cmd(argv) >= 2)
	{
		if (access(argv[1], F_OK) == -1)
			ft_error_fn(NULL, NULL, NULL);
		else
		{
			cmd_path = set_path(cmd_path, envp, find_path_idx(envp));
			if (cmd_path == NULL)
				ft_error_fn(NULL, NULL, NULL);
			setting_cmd(cmd_path, argc, argv, envp);
		}
	}
	else
	{
		ft_putendl_fd("usage : ./pipex file1 cmd1 cmd2 file2", 2);
		return (-1);
	}
	return (0);
}
