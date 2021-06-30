#include "pipex.h"

int count_cmd(char **argv)
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

int     main(int argc, char *argv[], char *envp[])
{
	char    **cmd_path;

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
