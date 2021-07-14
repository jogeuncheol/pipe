/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:51:54 by gejo              #+#    #+#             */
/*   Updated: 2021/07/03 19:15:47 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipe
{
	int	fd[2];
	int	backup_fd;
	int	cmd_idx;
	int	file2_fd;
}		t_pipe;

void	setting_cmd(char **cmd_path, int argc, char **argv, char **envp);
int		ft_pipex(char ***cmd_arr, char **envp, int file1_fd, int file2_fd);
char	***set_cmd_arr(char **cmd_path, char **argv, int idx);
char	**set_cmd(char **cmd_path, char **argv, int i);
int		find_sp(char *str);

char	**set_path(char **cmd_path, char **envp, int idx);
int		count_cmd(char **argv);

char	**set_cmd_sp(char **cmd_path, char *argv, int i);
char	**set_inner_cmd_sp(char **in_cmd_arr, char *argv, int cmd_op_count);
int		cmd_option_length(char *argv, int i);
char	*cmd_full_path(char **cmd_path, char *cmd_argv);

char	*cut_str(char *str);
char	*cut_str_single_q(char *str);
int		valid_argv(char **cmd_path, char **argv);
int		check_with_sp(char **cmd_path, char *str);
int		check_without_sp(char **cmd_path, char *str);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

int		ft_open(int idx, char **argv, char ***cmd_arr, int file1_fd);
void	ft_error_fn(char **cmd_path, char ***cmd_arr, char **in_cmd_arr);
char	**free_cmd_path(char **cmd_path);
char	***free_cmd_arr(char ***cmd_arr);

#endif
