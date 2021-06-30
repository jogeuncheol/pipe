#include "pipex.h"

char ***set_cmd_arr(char **cmd_path, char **argv)
{
	char ***cmd_arr;
	int count;
	int i;
	int idx;

	count = count_cmd(argv);
	cmd_arr = malloc((count + 1) * sizeof **cmd_arr);
	if (cmd_arr == NULL)
		return (NULL);
	idx = 0;
	i = 1;
	while (argv[(++i) + 1] != NULL)
	{
		if (find_sp(argv[i]) == 1)
			cmd_arr[idx] = set_cmd_sp(cmd_path, argv[i], 0);
		else
			cmd_arr[idx] = set_cmd(cmd_path, argv, i);
		if (cmd_arr[idx] == NULL)
			ft_error_fn(cmd_path, cmd_arr, NULL);
        while (argv[i][0] == '-')
			i++;
		idx++;
	}
	cmd_arr[idx] = NULL;
	return (cmd_arr);
}