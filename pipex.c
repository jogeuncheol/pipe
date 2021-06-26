#include "pipex.h"

void free_cmd_path(char **cmd_path)
{
	int i;

	i = 0;
	while (cmd_path[i] != NULL)
	{
		free(cmd_path[i]);
		i++;
	}
	free(cmd_path);
}

void free_cmd_argv(char **argv)
{
	int i;

	i = 2;
	while (argv[i + 1] != NULL)
	{
		if (argv[i][0] != '-')
		{
			free(argv[i]);
		}
		i++;
	}
}

void print_argv(char **argv)
{
    int i;

    i = 0;
    printf("=========================\n");
    while (argv[i] != NULL)
    {
        printf("argv[%d] : %s\n", i, argv[i]);
        i++;
    }
    printf("=========================\n");
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

int find_path(char **envp)
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

int vaild_argv(char **argv, char **envp)
{
    int i;
    int idx;
    int cmd_idx;
    int s_idx;
    int e_idx;

    char *cmd_path;
    char *tmp;

    i = 0;
    cmd_idx = 2;
    idx = find_path(envp);
    printf("envp[%d] : %s\n", idx, envp[idx]);
    while (idx != -1 && argv[cmd_idx + 1] != NULL)
    {
        while (envp[idx][i] != '/')
            i++;
        s_idx = i;
        while (envp[idx][i] != ':')
            i++;
        e_idx = i;
        cmd_path = path_str(envp[idx], s_idx, e_idx);
        tmp = cmd_path;
        cmd_path = ft_strjoin(tmp, argv[cmd_idx]);
        free(tmp);
        printf("cmd_path : %s\n", cmd_path);
        if (argv[cmd_idx + 1][0] == '-')
            cmd_idx++;
        if (access(cmd_path, F_OK | X_OK) == 0)
        {
            printf("find cmd : %s\n", cmd_path);
            cmd_idx++;
            i = 0;
        }
        printf("argv[%d] : %s\n", cmd_idx, argv[cmd_idx]);
    }
    return (1);
}

int valid_cmd(char **argv, char **cmd_path)
{
	int i;
	int c_idx;
	int c_flag;
	char *cmd;

	i = 2;
	while (argv[i + 1] != NULL)
	{
		while (argv[i][0] == '-')
			i++;
		if (argv[i + 1] == NULL)
			break;
		c_flag = 0;
		c_idx = 0;
		while (cmd_path[c_idx] != NULL && c_flag == 0)
		{
			cmd = ft_strjoin(cmd_path[c_idx], argv[i]);
			printf("cmd : %s\n", cmd);
			if (access(cmd, F_OK) == 0)
			{
				c_flag = 1;
				argv[i] = cmd;
			}
			else
				free(cmd);
			c_idx++;
		}
		if (c_flag != 1)
			return (0);
		i++;
	}
	print_argv(argv);
	return (c_flag);
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

char *cut_argv(char *argv, int s_idx, int e_idx)
{
	char *str;
	int i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (e_idx - s_idx + 1));
	if (str == NULL)
		return (NULL);
	while (s_idx < e_idx)
	{
		str[i] = argv[s_idx];
		i++;
		s_idx++;
	}
	str[i] = '\0';
	return (str);
}

char **split_argv(char **argv)
{
	int i;
	int j;
	int count;

	i = 2;
	count = 0;
	while (argv[i + 1] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ' && argv[i][j + 1] == '-')
			{
				count++;
				j++;
			}
			j++;
		}
		i++;
		count++;
	}
	printf("count : %d\n", count);
	// 여기까지 명령어와 옵션 갯수 찾기

	// 여기부터 명령어와 옵션 갯수로 spilt_argv 문자열 배열 만들고 리턴하기
	char **s_av;
	int idx;
	int s_idx;
	int e_idx;

	s_av = (char **)malloc(sizeof(char *) * (count + 1));
	if (s_av == NULL)
		return (NULL);
	i = 2;
	idx = 0;
	while (idx < count)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
				j++;
			s_idx = j;
			while ((argv[i][j] != ' ') && (argv[i][j] != '\0'))
			{
				j++;
			}
			e_idx = j;
			s_av[idx] = cut_argv(argv[i], s_idx, e_idx);
			idx++;
		}
		i++;
	}
	return (s_av);
}

char **full_cmd_option(int argc, char **argv, char **cmd_path)
{
    int p_idx;
    int av_idx;
    int i;
    int count;
    char *tmp;
    char **full_cmd_str;

    i = 0;
    p_idx = 0;
    av_idx = 2;
    count = count_cmd(argv);
    full_cmd_str = (char **)malloc(sizeof(char *) * (count + 1));
    while (cmd_path[p_idx] != NULL)
    {
        tmp = ft_strjoin(cmd_path[p_idx], argv[av_idx]);
        if (access(tmp, F_OK | X_OK) == 0)
        {
            full_cmd_str[i] = tmp;
            while (argv[av_idx + 1][0] == '-')
            {
                //tmp = ft_strjoin();
            }
        }
        else
            free(tmp);
    }
    
}

int ft_next_cmd(char **argv)
{
	static int i = 2;

	while (argv[i + 1] != NULL)
	{
		if (argv[i + 1][0] != '-')
			break ;
	}
}

int find_cmd_idx(char **argv, int i)
{
	int count;

	count = 1;
	while (argv[i + 1] != NULL)
	{
		if (argv[i + 1][0] != '-')
			break ;
		i++;
		count++;
	}
	return (count);
}

int ft_exec(char **argv, pid_t pid)
{
	int av_i = 2;
	int cmd_i;
	int idx;
	int count;
	char **exec_cmd;

	idx = av_i;
	count = 1;
	while (argv[av_i + 1] != NULL)
	{
		if (argv[av_i + 1][0] != '-')
			break ;
		av_i++;
		count++;
	}
	// 여기까지 첫 번째 명령어와 옵션 길이 count

	// 여기부터 count 만큼 exec_cmd 문자열 배열 생성
	int ii;

	ii = idx;
	idx = 0;
	exec_cmd = (char **)malloc(sizeof(char *) * (count + 1));
	if (exec_cmd == NULL)
		return (0);
	if (pid == 0)
		cmd_i = 2;
	else
		cmd_i = 2 + count;
	count = find_cmd_idx(argv, cmd_i);
	while (idx < count)
	{
		exec_cmd[idx] = ft_strdup(argv[cmd_i]);
		cmd_i++;
		idx++;
	}
	exec_cmd[idx] = NULL;
	printf("hello\n");
	if (execve(exec_cmd[0], exec_cmd, NULL) == -1)
	{
		perror(strerror(errno));
        return (errno);
	}
	return (1);
}

void ft_child(int *fd, char **argv, pid_t pid)
{
	int file1_fd;

	// close(fd[0]);
	// dup2(fd[1], 1);
	// file1_fd = open(argv[1], O_RDONLY);
	// dup2(file1_fd, 0);
	// dup2(fd[1], 1);
	ft_exec(argv, pid);
}

void ft_parent(int *fd, char **argv, int argc, pid_t pid)
{
	int file2_fd;
	pid_t wait_pid;

	// wait_pid = wait(0);
	wait(0);
	// close(fd[1]);
	// file2_fd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	// dup2(fd[0], 0);
	// dup2(file2_fd, 1);
	ft_exec(argv, pid);
}

int ft_pipex(int argc, char **argv)
{
	int i;
	int fd[2];
	int backup_read_fd;
	pid_t pid;

	i = 2;
	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		ft_putendl_fd("fork fail\n", 2);
	else if (pid == 0) // child
	{
		ft_child(fd, argv, pid);
	}
	else
	{
		ft_parent(fd, argv, argc, pid);
	}
	return (1);
}

int main(int argc, char *argv[], char *envp[])
{
    char **cmd_path;
	char **cmd_arr;
	int valid;

    if (argc > 3)
    {
        if (access(argv[1], F_OK) == -1)
        {
            perror(strerror(errno));
            return (errno);
        }
        else
        {
            // pipex start
            cmd_path = set_path(cmd_path, envp);
            print_path(cmd_path);
			valid = valid_cmd(argv, cmd_path);
			printf("cmd count : %d\n", count_cmd(argv));
			if (valid == 0)
			{
				perror(strerror(errno));
            	return (errno);
			}
			// pipex(argv, cmd_path);
			if (ft_pipex(argc, argv) == 0)
				return (-1);
			free_cmd_path(cmd_path);
			free_cmd_argv(argv);
        }
    }
    else
    {
        ft_putendl_fd("usage : ./pipex file1 cmd1 cmd2 file2", 2);
        return (-1);
    }
    return (0);
}