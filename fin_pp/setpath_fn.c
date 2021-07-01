#include "pipex.h"

int length_of_path(char *envp)
{
	int i;
	int len;

	i = 0;
	len = 1;
	while (envp[i] != '\0')
	{
		if (envp[i] == ':')
			len++;
		i++;
	}
	return (len);
}

char *path_str(char *full_path, int s_idx, int e_idx)
{
	int i;
	char *str;

	str = malloc(sizeof(str) * (e_idx - s_idx) + 2);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < e_idx - s_idx)
	{
		str[i] = full_path[s_idx + i];
		i++;
	}
	str[i++] = '/';
	str[i] = '\0';
	return (str);
}

char **set_path(char **cmd_path, char **envp, int idx)
{
	int i;
	int s_idx;
	int e_idx;
	int j;

	j = 0;
	i = 0;
	cmd_path = malloc((length_of_path(envp[idx]) + 1) * sizeof *cmd_path);
	if (cmd_path == NULL)
		return (NULL);
	while (envp[idx][i] != '\0')
	{
		while (envp[idx][i] != '/')
			i++;
		s_idx = i;
		while (envp[idx][i] != '\0' && envp[idx][i] != ':')
			i++;
		e_idx = i;
		cmd_path[j] = path_str(envp[idx], s_idx, e_idx);
		if (cmd_path[j] == NULL)
			ft_error_fn(cmd_path, NULL, NULL);
		j++;
	}
	cmd_path[j] = NULL;
	return (cmd_path);
}