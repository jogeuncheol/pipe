/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_cmd_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 02:31:26 by gejo              #+#    #+#             */
/*   Updated: 2021/07/21 02:31:27 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	***ft_set_cmd_arr(char **cmd_path, char **argv, int idx)
{
	char	***cmd_arr;
	int		count;
	int		i;

	count = ft_count_cmd(argv);
	cmd_arr = malloc((count + 1) * sizeof(char **));
	if (cmd_arr == NULL)
		return (NULL);
	i = 1;
	while (argv[(++i) + 1] != NULL)
	{
		while (argv[i][0] == '-')
			i++;
		if (argv[i + 1] == NULL)
			break ;
		if (ft_find_sp(argv[i]) == 1)
			cmd_arr[idx] = ft_set_cmd_with_sp(cmd_path, argv[i], 0);
		else
			cmd_arr[idx] = ft_set_cmd_without_sp(cmd_path, argv, i);
		if (cmd_arr[idx] == NULL)
			ft_error(cmd_path, cmd_arr);
		idx++;
	}
	cmd_arr[idx] = NULL;
	return (cmd_arr);
}
