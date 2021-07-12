/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_arr_fn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:51:32 by gejo              #+#    #+#             */
/*   Updated: 2021/07/03 19:02:23 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	***set_cmd_arr(char **cmd_path, char **argv, int idx)
{
	char	***cmd_arr;
	int		count;
	int		i;

	count = count_cmd(argv);
	cmd_arr = malloc((count + 1) * sizeof(**cmd_arr));
	if (cmd_arr == NULL)
		return (NULL);
	i = 1;
	while (argv[(++i) + 1] != NULL)
	{
		while (argv[i][0] == '-')
			i++;
		if (argv[i + 1] == NULL)
			break ;
		if (find_sp(argv[i]) == 1)
			cmd_arr[idx] = set_cmd_sp(cmd_path, argv[i], 0);
		else
			cmd_arr[idx] = set_cmd(cmd_path, argv, i);
		if (cmd_arr[idx] == NULL)
			ft_error_fn(cmd_path, cmd_arr, NULL);
		idx++;
	}
	cmd_arr[idx] = NULL;
	return (cmd_arr);
}
