/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fn_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:52:03 by gejo              #+#    #+#             */
/*   Updated: 2021/07/03 19:08:17 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	*cut_str(char *str)
{
	int		i;
	int		j;
	char	*cut_cmd;

	j = 0;
	while (str[j] == ' ')
		j++;
	i = j;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	cut_cmd = (char *)malloc(sizeof(char) * (i + 1));
	if (cut_cmd == NULL)
		return (NULL);
	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		cut_cmd[i] = str[i];
		i++;
	}
	cut_cmd[i] = '\0';
	return (cut_cmd);
}

char	*cut_str_single_q(char *str)
{
	int i;
	char *cut_cmd;

	i = 0;
	while (str[i + 1] != '\'')
		i++;
	cut_cmd = malloc((i + 1) * sizeof(char));
	if (cut_cmd == NULL)
		return (NULL);
	i = 0;
	while (str[i + 1] != '\'' && str[i] != '\0')
	{
		cut_cmd[i] = str[i + 1];
		i++;
	}
	cut_cmd[i] = '\0';
	return (cut_cmd);
}

int		find_sp(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int		check_with_sp(char **cmd_path, char *str)
{
	int		i;
	char	*cmd;
	char	*c_cmd;

	c_cmd = cut_str(str);
	if (c_cmd == NULL)
		ft_error_fn(cmd_path, NULL, NULL);
	i = 0;
	while (cmd_path[i] != NULL)
	{
		cmd = ft_strjoin(cmd_path[i], c_cmd);
		if (cmd == NULL)
			ft_error_fn(cmd_path, NULL, NULL);
		if (access(cmd, F_OK) == 0)
		{
			free(cmd);
			free(c_cmd);
			return (1);
		}
		free(cmd);
		i++;
	}
	free(c_cmd);
	return (0);
}

int		check_without_sp(char **cmd_path, char *str)
{
	int		i;
	char	*cmd;

	i = 0;
	while (cmd_path[i] != NULL)
	{
		cmd = ft_strjoin(cmd_path[i], str);
		if (cmd == NULL)
			ft_error_fn(cmd_path, NULL, NULL);
		if (access(cmd, F_OK) == 0)
		{
			free(cmd);
			return (1);
		}
		free(cmd);
		i++;
	}
	return (0);
}
