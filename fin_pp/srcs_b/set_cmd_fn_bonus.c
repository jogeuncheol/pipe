/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_fn_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:52:38 by gejo              #+#    #+#             */
/*   Updated: 2021/07/03 19:01:04 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char
	**set_inner_cmd(char **in_cmd_arr, char **argv, int cmd_op_count, int av_i)
{
	int i;

	i = 0;
	while (i < cmd_op_count)
	{
		in_cmd_arr[i] = ft_strdup(argv[av_i + i]);
		if (in_cmd_arr[i] == NULL)
			return (free_cmd_path(in_cmd_arr));
		i++;
	}
	in_cmd_arr[i] = NULL;
	return (in_cmd_arr);
}

char
	**set_cmd(char **cmd_path, char **argv, int i)
{
	char	**in_cmd_arr;
	char	*cmd;
	int		cmd_op_count;

	cmd_op_count = 1;
	while (argv[i + cmd_op_count + 1] != NULL && argv[i + cmd_op_count][0] == '-')
		cmd_op_count++;
	in_cmd_arr = malloc((cmd_op_count + 1) * sizeof(*in_cmd_arr));
	if (in_cmd_arr == NULL)
		return (NULL);
	in_cmd_arr = set_inner_cmd(in_cmd_arr, argv, cmd_op_count, i);
	if (in_cmd_arr == NULL)
		return (NULL);
	cmd = cmd_full_path(cmd_path, in_cmd_arr[0]);
	if (cmd == NULL)
		return (free_cmd_path(in_cmd_arr));
	free(in_cmd_arr[0]);
	in_cmd_arr[0] = cmd;
	return (in_cmd_arr);
}
