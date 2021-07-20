#include "../include/pipex.h"

char	**ft_set_inner_cmd(char **in_cmd_arr, char **argv, int cmd_op_count, int i)
{
	int		idx;

	idx = 0;
	while (i < cmd_op_count)
	{
		in_cmd_arr[idx] = ft_strdup(argv[i + idx]);
		if (in_cmd_arr[idx] == NULL)
			return (ft_free_cmd_path(in_cmd_arr));
		i++;
	}
	in_cmd_arr[idx] = NULL;
	return (in_cmd_arr);
}

char	**set_cmd(char **cmd_path, char **argv, int i)
{
	char	**in_cmd_arr;
	char	*cmd;
	int		cmd_op_count;

	cmd_op_count = 1;
	while (argv[i + cmd_op_count + 1] != NULL
			&& argv[i + cmd_op_count][0] == '-')
		cmd_op_count++;
	in_cmd_arr = malloc((cmd_op_count + 1) * sizeof(char*));
	if (in_cmd_arr == NULL)
		return (NULL);
	in_cmd_arr = ft_set_inner_cmd(in_cmd_arr, argv, cmd_op_count, i);
	if (in_cmd_arr == NULL)
		return (NULL);
	cmd = cmd_full_path(cmd_path, in_cmd_arr[0]);
	if (cmd == NULL)
		return (ft_free_cmd_path(in_cmd_arr));
	free(in_cmd_arr[0]);
	in_cmd_arr[0] = cmd;
	return (in_cmd_arr);
}
