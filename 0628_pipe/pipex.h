#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

void	setting_cmd(char **cmd_path, int argc, char **argv, char **envp);
void	ft_pipex(char ***cmd_arr, char **envp, int file1_fd, int file2_fd);
char	***set_cmd_arr(char **cmd_path, char **argv);
char	**set_cmd(char **cmd_path, char **argv, int i);
int		find_sp(char *str);

char	**set_path(char **cmd_path, char **envp, int idx);
int		count_cmd(char **argv);

char	**set_cmd_sp(char **cmd_path, char *argv, int i);
char	*cmd_full_path(char **cmd_path, char **in_cmd_arr);
void	set_inner_cmd(char ***in_cmd_arr, char *argv, int cmd_op_count);
int		cmd_option_length(char *argv, int i);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

void	ft_error_fn(char **cmd_path, char ***cmd_arr, char **in_cmd_arr);
char	**free_cmd_path(char **cmd_path);
char	***free_cmd_arr(char ***cmd_arr);

#endif