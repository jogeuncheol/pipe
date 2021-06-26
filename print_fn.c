#include "pipex.h"

void malloc_error(char **cmd)
{
    int i;

    i = 0;
    while (cmd[i] != NULL)
    {
        free(cmd[i]);
        cmd[i] = NULL;
        i++;
    }
    free(cmd);
    exit(1);
}

void free_cmd_argv(char **argv)
{
	int i;

	i = 2;
	while (argv[i + 1] != NULL)
	{
		if (argv[i][0] == '/')
		{
			free(argv[i]);
		}
		i++;
	}
}

void print_path(char **cmd_path)
{
    int i = 0;
    while (cmd_path[i] != NULL)
    {
        printf("cmd_path : %s\n", cmd_path[i]);
        i++;
    }
}