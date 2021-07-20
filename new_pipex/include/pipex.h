#ifndef PIPEX_H
# define PIPEX_h

# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_pipe
{
	int	fd[2];
	int	backup_fd;
	int	cmd_idx;
	int	file2_fd;
}		t_pipe;

int		ft_count_cmd(char **argv);

char	**ft_set_path(char **cmd_path, char **envp, int idx);
char	***ft_set_cmd_arr(char **cmd_path, char **argv, int idx);
char	**ft_set_cmd(char **cmd_path, char **argv, int i);
char	**ft_set_cmd_with_sp(char **cmd_path, char *argv, int i);
char	*ft_cmd_full_path(char **cmd_path, char *cmd_argv);
char	*ft_cut_str_single_q(char *str);
char	*ft_cut_str(char *str);
int		ft_find_sp(char *str);

size_t	ft_strlen(const char *str);
void	ft_putstr_fd(const char *str, int fd);
char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *str1, const char str2);
char	ft_strncmp(const char *s1, const char *s2, size_t n);


int		ft_open(int idx, char **argv, char ***cmd_arr, int file1_fd);
void	**ft_free_cmd_path(char **cmd_path);
void	***ft_free_cmd_arr(char ***cmd_arr);
void	ft_error(char **cmd_path, char ***cmd_arr);

#endif
