/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_path_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 02:30:59 by gejo              #+#    #+#             */
/*   Updated: 2021/07/25 13:08:47 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	ft_length_of_path(char *envp)
{
	int		i;
	int		len;

	i = 0;
	len = 1;
	while (envp[i] != '\0')
	{
		if (envp[i] == ':')
			len++;
		i++;
	}
	return (len);
}

char	*ft_path_str(char *full_path, int s_idx, int e_idx)
{
	int		i;
	char	*str;

	str = malloc((e_idx - s_idx + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < e_idx - s_idx)
	{
		str[i] = full_path[s_idx + i];
		i++;
	}
	str[i++] = '/';
	str[i] = '\0';
	return (str);
}

char	**ft_set_path(char **cmd_path, char **envp, int idx)
{
	int		i;
	int		j;
	int		s_idx;
	int		e_idx;

	i = 0;
	j = 0;
	cmd_path = malloc((ft_length_of_path(envp[idx]) + 1) * sizeof(char *));
	if (cmd_path == NULL)
		return (NULL);
	while (envp[idx][i] != '\0')
	{
		while (envp[idx][i] != '/')
			i++;
		s_idx = i;
		while (envp[idx][i] != '\0' && envp[idx][i] != ':')
			i++;
		e_idx = i;
		cmd_path[j] = ft_path_str(envp[idx], s_idx, e_idx);
		if (cmd_path[j] == NULL)
			ft_error(cmd_path, NULL);
		j++;
	}
	cmd_path[j] = NULL;
	return (cmd_path);
}
