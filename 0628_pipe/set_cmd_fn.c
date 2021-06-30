#include "pipex.h"

char **set_cmd(char **cmd_path, char **argv, int i)
{
	char **in_cmd_arr;
	char *cmd;
	int c_idx;
	int cmd_op_count;
	int ica_idx;

	cmd_op_count = 1;
	while (argv[i + cmd_op_count][0] == '-')
		cmd_op_count++;
	in_cmd_arr = malloc((cmd_op_count + 1) * sizeof *in_cmd_arr);
	if (in_cmd_arr == NULL)
		return (NULL);
	c_idx = 0;
	cmd = cmd_full_path(cmd_path, argv[i]);
	if (cmd == NULL)
		return (free_cmd_path(in_cmd_arr));
	ica_idx = 0;
	in_cmd_arr[ica_idx++] = cmd;
	if (cmd == NULL)
		return (in_cmd_arr);
	while (ica_idx < cmd_op_count)
	{
		in_cmd_arr[ica_idx] = ft_strdup(argv[i + ica_idx]);
		if (in_cmd_arr[ica_idx] == NULL)
			return (free_cmd_path(in_cmd_arr));
		ica_idx++;
	}
	in_cmd_arr[ica_idx] = NULL;
	return (in_cmd_arr);
}