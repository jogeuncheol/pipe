#include "pipex.h"

int cmd_option_length(char *argv, int i)
{
    int len;

    len = 0;
    while (argv[i] != '\0')
	{
		if (argv[i] != ' ' && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
			len++;
		i++;
	}
    return (len)
}

void set_inner_cmd(char ***in_cmd_arr, char *argv, int cmd_op_count)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (count < cmd_op_count)
	{
		while (argv[i] == ' ')
			i++;
		(*in_cmd_arr)[count] = cut_str(&argv[i]);
		if ((*in_cmd_arr)[count] == NULL)
			return (free_cmd_path(in_cmd_arr));
		while (argv[i] != '\0' && argv[i] != ' ')
			i++;
		count++;
	}
    (*in_cmd_arr)[count] = NULL;
}

char *cmd_full_path(char **cmd_path, char *cmd_argv)
{
    int c_idx;
    char *cmd;

    c_idx = 0;
    while (cmd_path[c_idx] != NULL)
	{
		cmd = ft_strjoin(cmd_path[c_idx], cmd_argv);
		if (cmd == NULL)
			return (NULL);
		if (access(cmd, F_OK) == 0)
			break ;
		free(cmd);
		c_idx++;
	}
    return (cmd);
}

char **set_cmd_sp(char **cmd_path, char *argv, int i)
{
	char **in_cmd_arr;
	char *cmd;
	int cmd_op_count;

	cmd_op_count = cmd_option_length(argv, i);
	in_cmd_arr = malloc((cmd_op_count + 1) * sizeof *in_cmd_arr);
	if (in_cmd_arr == NULL)
		return (NULL);
    set_inner_cmd(&in_cmd_arr, argv, cmd_op_count);
	cmd = cmd_full_path(cmd_path, in_cmd_arr[0]);
	if (cmd == NULL)
		return (free_cmd_path(in_cmd_arr));
    free(in_cmd_arr[0]);
	in_cmd_arr[0] = cmd;
	return (in_cmd_arr);
}