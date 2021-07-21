/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_cmd_sp_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 02:31:44 by gejo              #+#    #+#             */
/*   Updated: 2021/07/21 19:59:16 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	ft_cmd_option_length(char *argv, int i)
{
	int		len;

	len = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '\'' || argv[i] == '\"')
		{
			len++;
			break ;
		}
		if (argv[i] != ' ' && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
			len++;
		i++;
	}
	return (len);
}

char	**ft_set_inner_cmd_sp(char **in_cmd_arr, char *argv, int cmd_op_count)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (count < cmd_op_count)
	{
		while (argv[i] == ' ')
			i++;
		if (argv[i] == '\'' || argv[i] == '\"')
			in_cmd_arr[count] = ft_cut_str_quote(&argv[i], argv[i]);
		else
			in_cmd_arr[count] = ft_cut_str(&argv[i]);
		if (in_cmd_arr[count] == NULL)
		{
			ft_free_cmd_path(in_cmd_arr);
			return (NULL);
		}
		while (argv[i] != '\0' && argv[i] != ' ')
			i++;
		count++;
	}
	in_cmd_arr[count] = NULL;
	return (in_cmd_arr);
}

char	*ft_cmd_full_path(char **cmd_path, char *cmd_argv)
{
	int		c_idx;
	char	*cmd;

	c_idx = 0;
	while (cmd_path[c_idx] != NULL)
	{
		cmd = ft_strjoin(cmd_path[c_idx], cmd_argv);
		if (cmd == NULL)
			return (NULL);
		if (access(cmd, F_OK) == 0)
			break ;
		if (cmd_path[c_idx + 1] == NULL)
			break ;
		free(cmd);
		c_idx++;
	}
	return (cmd);
}

char	**ft_set_cmd_with_sp(char **cmd_path, char *argv, int i)
{
	char	**in_cmd_arr;
	char	*cmd;
	int		cmd_op_count;

	cmd_op_count = ft_cmd_option_length(argv, i);
	in_cmd_arr = malloc((cmd_op_count + 1) * sizeof(char *));
	if (in_cmd_arr == NULL)
		return (NULL);
	in_cmd_arr = ft_set_inner_cmd_sp(in_cmd_arr, argv, cmd_op_count);
	if (in_cmd_arr == NULL)
		return (NULL);
	cmd = ft_cmd_full_path(cmd_path, in_cmd_arr[0]);
	if (cmd == NULL)
	{
		ft_free_cmd_path(in_cmd_arr);
		return (NULL);
	}
	free(in_cmd_arr[0]);
	in_cmd_arr[0] = cmd;
	return (in_cmd_arr);
}
