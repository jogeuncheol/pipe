#include "pipex.h"

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

char **set_path(char **cmd_path, char **envp)
{
    int i;
    int idx;
    int s_idx;
    int e_idx;
    int j;

    j = 0;
    i = 0;
    idx = find_path(envp);
    cmd_path = (char **)malloc(sizeof(char *) * (length_of_path(envp[idx]) + 1));
    while (envp[idx][i] != '\0')
    {
        while (envp[idx][i] != '/')
            i++;
        s_idx = i;
        while (envp[idx][i] != '\0' && envp[idx][i] != ':')
            i++;
        e_idx = i;
        cmd_path[j] = path_str(envp[idx], s_idx, e_idx);
        j++;
    }
    cmd_path[j] = NULL;
    return (cmd_path);
}