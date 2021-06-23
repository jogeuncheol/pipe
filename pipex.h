#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

# include <stdio.h>

typedef struct s_cmd
{
    char *cmd_str;
    struct s_cmd *next;
}           t_cmd;

char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
size_t		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

int find_path(char **envp);
char *path_str(char *full_path, int s_idx, int e_idx);
int length_of_path(char *envp);
char **set_path(char **cmd_path, char **envp);

#endif