#ifndef PIPEX_H
# define PIPEX_h

# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

int		ft_count_cmd(char **argv);

char	**ft_set_path(char **cmd_path, char **envp, int idx);
char	***ft_set_cmd_arr(char **cmd_path, char **argv, int idx);
char	**ft_set_cmd(char **cmd_path, char **argv, int i);
char	**ft_set_cmd_with_sp(char **cmd_path, char *argv, int i);
char	*ft_cmd_full_path(char **cmd_path, char *cmd_argv);
char	*ft_cut_str_single_q(char *str);
char	*ft_cut_str(char *str);

char	*ft_strjoin(char *str1, char str2);

void	ft_error(char **cmd_path, char ***cmd_arr);

#endif
