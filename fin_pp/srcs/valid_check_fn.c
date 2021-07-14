/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_fn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:52:45 by gejo              #+#    #+#             */
/*   Updated: 2021/07/03 19:06:30 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	valid_argv(char **cmd_path, char **argv)
{
	int		i;
	int		valid_check;

	i = 2;
	while (argv[i] != NULL && argv[i + 1] != NULL)
	{
		valid_check = 0;
		while (argv[i][0] == '-')
			i++;
		if (argv[i + 1] == NULL)
			break ;
		if (find_sp(argv[i]) == 1)
			valid_check = check_with_sp(cmd_path, argv[i]);
		else
			valid_check = check_without_sp(cmd_path, argv[i]);
		if (valid_check == 1)
			i++;
		else
			return (0);
	}
	return (1);
}
