#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

void free_cmd_arr(char ***cmd_arr)
{
	int i;
	int j;

	i = 0;
	while (cmd_arr[i] != NULL)
	{
		j = 0;
		while (cmd_arr[i][j] != NULL)
		{
			free(cmd_arr[i][j]);
			cmd_arr[i][j] = NULL;
			j++;
		}
		free(cmd_arr[i]);
		cmd_arr[i] = NULL;
		i++;
	}
	free(cmd_arr);
	cmd_arr = NULL;
}

void free_cmd_path(char **cmd_path)
{
	int i;

	i = 0;
	while (cmd_path[i] != NULL)
	{
		free(cmd_path[i]);
		cmd_path[i] = NULL;
		i++;
	}
	free(cmd_path);
}

size_t		ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		*(ptr + i) = *((char *)s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s1 != '\0')
		*(ptr + i++) = *(s1++);
	while (i < len && *s2 != '\0')
		*(ptr + i++) = *(s2++);
	*(ptr + i) = '\0';
	return (ptr);
}

void print_path(char **cmd_path)
{
	int i = 0;
	while (cmd_path[i] != NULL)
	{
		printf("cmd_path : %s\n", cmd_path[i]);
		i++;
	}
}

void malloc_error(char **cmd)
{
	int i;

	i = 0;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		cmd[i] = NULL;
		i++;
	}
	free(cmd);
	exit(1);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else if (*s1 != *s2)
			break ;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int find_path_idx(char **envp)
{
	int i;
	int j;
	char *path;

	i = 0;
	path = "PATH=";
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], path, 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int length_of_path(char *envp)
{
	int i;
	int len;

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

char *path_str(char *full_path, int s_idx, int e_idx)
{
	int i;
	char *str;

	str = (char *)malloc(sizeof(char) * (e_idx - s_idx) + 2);
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

char **set_path2(char **cmd_path, char **envp, int idx)
{
	int i;
	int s_idx;
	int e_idx;
	int j;

	j = 0;
	i = 0;
	cmd_path = (char **)malloc(sizeof(char *) * (length_of_path(envp[idx]) + 1));
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
		cmd_path[j] = path_str(envp[idx], s_idx, e_idx);
		if (cmd_path[j] == NULL)
			malloc_error(cmd_path);
		j++;
	}
	cmd_path[j] = NULL;
	return (cmd_path);
}

int find_sp(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

char *cut_str(char *str)
{
	int i;
	int j;
	char *cut_cmd;

	printf("cut_str : %s\n", str);
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

int check_with_sp(char **cmd_path, char *str)
{
	int i;
	char *cmd;
	char *c_cmd;

	c_cmd = cut_str(str);
	i = 0;
	while (cmd_path[i] != NULL)
	{
		cmd = ft_strjoin(cmd_path[i], c_cmd);
		printf("cmd : %s\n", cmd);
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

int check_without_sp(char **cmd_path, char *str)
{
	int i;
	char *cmd;

	i = 0;
	while (cmd_path[i] != NULL)
	{
		cmd = ft_strjoin(cmd_path[i], str);
		printf("cmd : %s\n", cmd);
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

int valid_argv(char **cmd_path, char **argv)
{
	int i;
	int valid_check;

	i = 2;
	while (argv[i + 1] != NULL)
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

int count_cmd(char **argv)
{
    int i;
    int count;

    i = 2;
    count = 0;
    while (argv[i + 1] != NULL)
    {
        if (argv[i][0] == '-')
            i++;
        else
        {
            count++;
            i++;
        }
    }
    return (count);
}

char **set_cmd_sp(char **in_cmd_arr, char **cmd_path, char *argv, int i)
{
	char *tmp;
	char *cmd;
	int c_idx;
	int cmd_op_count;
	int j;

	printf("argv : %s\n", argv);
	cmd_op_count = 0;
	while (argv[i] != '\0')
	{
		printf("argv[i] : %c, count : %d\n", argv[i], cmd_op_count);
		if (argv[i] != ' ' && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
			cmd_op_count++;
		i++;
	}
	printf("cmd_op_count : %d\n", cmd_op_count);
	in_cmd_arr = (char **)malloc(sizeof(char *) * (cmd_op_count + 1));
	if (in_cmd_arr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < cmd_op_count)
	{
		while (argv[j] == ' ')
			j++;
		in_cmd_arr[i] = cut_str(&argv[j]);
		while (argv[j] != '\0' && argv[j] != ' ')
			j++;
		i++;
	}
	in_cmd_arr[i] = NULL;
	c_idx = 0;
	tmp = in_cmd_arr[0];
	while (cmd_path[c_idx] != NULL)
	{
		cmd = ft_strjoin(cmd_path[c_idx], tmp);
		printf("cmd : %s\n", cmd);
		if (access(cmd, F_OK) == 0)
			break ;
		free(cmd);
		c_idx++;
	}
	free(tmp);
	in_cmd_arr[0] = cmd;
	return (in_cmd_arr);
}

char **set_cmd(char **cmd_path, char **argv, int i)
{
	char **in_cmd_arr;
	char *cmd;
	int c_idx;
	int cmd_op_count;
	int ica_idx;
	
	cmd_op_count = 1;
	while (argv[i + cmd_op_count][0] == '-')
		cmd_op_count++;
	printf("cmd_op_count : %d\n", cmd_op_count);
	in_cmd_arr = (char **)malloc(sizeof(char *) * (cmd_op_count + 1));
	if (in_cmd_arr == NULL)
		return (NULL);
	c_idx = 0;
	while (cmd_path[c_idx] != NULL)
	{
		cmd = ft_strjoin(cmd_path[c_idx], argv[i]);
		printf("cmd : %s\n", cmd);
		if (access(cmd, F_OK) == 0)
			break ;
		free(cmd);
		c_idx++;
	}
	ica_idx = 0;
	in_cmd_arr[ica_idx++] = cmd;
	while (ica_idx < cmd_op_count)
	{
		in_cmd_arr[ica_idx] = ft_strdup(argv[i + ica_idx]);
		ica_idx++;
	}
	in_cmd_arr[ica_idx] = NULL;
	return (in_cmd_arr);
}

char ***set_cmd_arr(char **cmd_path, char **argv)
{
	char ***cmd_arr;
	char **in_cmd_arr;
	int cmd_count;
	int i;
	int idx;

	cmd_count = count_cmd(argv);
	printf("cmd_count : %d\n", cmd_count);
	cmd_arr = (char ***)malloc(sizeof(char*) * (cmd_count + 1));
	if (cmd_arr == NULL)
		return (NULL);
	idx = 0;
	i = 2;
	while (argv[i + 1] != NULL)
	{
		while (argv[i][0] == '-')
			i++;
		if (argv[i + 1] == NULL)
			break ;
		if (find_sp(argv[i]) == 1)
			cmd_arr[idx++] = set_cmd_sp(in_cmd_arr, cmd_path, argv[i], 0);
		else
			cmd_arr[idx++] = set_cmd(cmd_path, argv, i);
		i++;
	}
	cmd_arr[idx] = NULL;
	return (cmd_arr);
}

void ft_pipex(char ***cmd_arr, char **envp, int file1_fd, int file2_fd)
{
	int i;
	int fd[2];
	int b_fd;
	pid_t pid;

	i = 0;
	b_fd = file1_fd;
	while (cmd_arr[i] != NULL)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			dup2(b_fd, 0);
			if (cmd_arr[i + 1] != NULL)
				dup2(fd[1], 1);
			else
			 	dup2(file2_fd, 1);
			execve(cmd_arr[i][0], cmd_arr[i], envp);
		}
		else if (pid > 0)
		{
			wait(0);
			close(fd[1]);
			b_fd = fd[0];
		}
		i++;
	}
}

void setting_cmd(char **cmd_path, int argc, char **argv, char **envp)
{
	char ***cmd_arr;
	int file1_fd;
	int file2_fd;

	if (valid_argv(cmd_path, argv) == 1)
	{
		printf("valid_argv check_ok\n");
		cmd_arr = set_cmd_arr(cmd_path, argv);
		file1_fd = open(argv[1], O_RDONLY);
		file2_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		ft_pipex(cmd_arr, envp, file1_fd, file2_fd);
		close(file2_fd);
		free_cmd_arr(cmd_arr);
	}
	else
	{
		// error_fn(cmd_path);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	char **cmd_path;

	if (argc > 3 && count_cmd(argv) >= 2)
	{
		if (access(argv[1], F_OK) == -1)
		{
			perror(strerror(errno));
			return (errno);
		}
		else
		{
			cmd_path = set_path2(cmd_path, envp, find_path_idx(envp));
			if (cmd_path == NULL)
				return (-1);
			setting_cmd(cmd_path, argc, argv, envp);
			free_cmd_path(cmd_path);
		}
	}
	else
	{
		printf("usage : ./pipex file1 cmd1 cmd2 [... cmdn] file2\n");
		return (-1);
	}
	return (0);
}
