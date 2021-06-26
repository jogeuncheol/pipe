#include "pipex.h"

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>

#include <stdio.h>
#include <string.h>

int find_path_idx(char **envp)
{
    int i;
    int j;
    char *path;

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

    str = (char *)malloc(sizeof(char) * (e_idx - s_idx) + 2);
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

char **set_path2(char **cmd_path, char **envp, int idx)
{
    int i;
    int s_idx;
    int e_idx;
    int j;

    j = 0;
    i = 0;
    cmd_path = (char **)malloc(sizeof(char *) * (length_of_path(envp[idx]) + 1));
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
            malloc_error(cmd_path);
        j++;
    }
    cmd_path[j] = NULL;
    return (cmd_path);
}

int valid_cmd(char **argv, char **cmd_path)
{
	int i;
	int c_idx;
	int c_flag;
	char *cmd;

	i = 2;
	while (argv[i + 1] != NULL)
	{
		while (argv[i][0] == '-')
			i++;
		if (argv[i + 1] == NULL)
			break;
		c_flag = 0;
		c_idx = 0;
		while (cmd_path[c_idx] != NULL && c_flag == 0)
		{
			cmd = ft_strjoin(cmd_path[c_idx], argv[i]);
			printf("cmd : %s\n", cmd);
			if (access(cmd, F_OK) == 0)
			{
				c_flag = 1;
				argv[i] = cmd;
			}
			else
				free(cmd);
			c_idx++;
		}
        printf("argv[i - 1] : %s\n", argv[i - 1]);
		if (c_flag == 0)
        {
            if (access(argv[i - 1], F_OK) == 0)
            {
                i++;
                c_flag = 1;
                continue;
            }
			return (0);
        }
		i++;
	}
	return (c_flag);
}

int main(int argc, char *argv[], char *envp[])
{
	char **cmd_path;
	t_cmd cmd_list;
	int cmd_valid;

	if (argc > 3)
	{
		if (access(argv[1], F_OK) == -1)
		{
			perror(strerror(errno));
			return (errno);
		}
		else
		{
			cmd_path = set_path2(cmd_path, envp, find_path_idx(envp));
			if (cmd_path == NULL)
				return (-1);
			print_path(cmd_path);
			cmd_valid = valid_cmd(argv, cmd_path);
			printf("cmd_valid : %d\n", cmd_valid);
		}
	}
	else
	{
		ft_putendl_fd("usage : ./pipex file1 cmd1 cmd2 [... cmdn] file2", 2);
		return (-1);
	}
	return (0);
}