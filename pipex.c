#include "pipex.h"

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
        if (argv[cmd_idx + 1][0] == '-')
            cmd_idx++;
    }
}

int main(int argc, char *argv[], char *envp[])
{
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
        }
    }
    else
    {
        ft_putendl_fd("usage : ./pipex file1 cmd1 cmd2 file2", 2);
        return (-1);
    }
    return (0);
}