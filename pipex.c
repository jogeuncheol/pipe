#include "pipex.h"

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
            while (argv[av_idx + 1] == '-')
            {
                tmp = ft_strjoin();
            }
        }
        else
            free(tmp);
    }
    
}

int main(int argc, char *argv[], char *envp[])
{
    char **cmd_path;

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
        }
    }
    else
    {
        ft_putendl_fd("usage : ./pipex file1 cmd1 cmd2 file2", 2);
        return (-1);
    }
    return (0);
}