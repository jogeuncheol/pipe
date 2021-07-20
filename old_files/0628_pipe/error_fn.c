#include "pipex.h"

char ***free_cmd_arr(char ***cmd_arr)
{
	int i;
	int j;

	i = 0;
	while (cmd_arr[i] != NULL)
	{
		j = 0;
		while (cmd_arr[i][j] != NULL)
		{
			free(cmd_arr[i][j]);
			cmd_arr[i][j] = NULL;
			j++;
		}
		free(cmd_arr[i]);
		cmd_arr[i] = NULL;
		i++;
	}
	free(cmd_arr);
	cmd_arr = NULL;
	return (cmd_arr);
}

char **free_cmd_path(char **cmd_path)
{
	int i;

	i = 0;
	while (cmd_path[i] != NULL)
	{
		free(cmd_path[i]);
		cmd_path[i] = NULL;
		i++;
	}
	free(cmd_path);
	cmd_path = NULL;
	return (cmd_path);
}

void ft_error_fn(char **cmd_path, char ***cmd_arr, char **in_cmd_arr)
{
	if (cmd_path != NULL)
		free_cmd_path(cmd_path);
	if (cmd_arr != NULL)
		free_cmd_arr(cmd_arr);
	if (in_cmd_arr != NULL)
		free_cmd_path(in_cmd_arr);
	perror(strerror(errno));
	exit(errno);
}