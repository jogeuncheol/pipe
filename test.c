#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "pipex.h"

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
    // while (envp[i] != NULL)
    // {
    //     j = 0;
    //     while (envp[i][j] == path[j])
    //     {
    //         j++;
    //         if (j == 5)
    //             return (i);
    //     }
    //     i++;
    // }
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

t_cmd *creat_node(char *envp_str)
{
    t_cmd *node;

    node = (t_cmd *)malloc(sizeof(t_cmd));
    if (node == NULL)
        return (NULL);
    node->cmd_str = envp_str;
    node->next = NULL;
    return (node);
}

t_cmd *link_cmd(t_cmd **cmd, char *envp_str)
{
    t_cmd *head;
    t_cmd *new_cmd;

    new_cmd = creat_node(envp_str);
    if (new_cmd == NULL)
        return (NULL);
    if (*cmd == NULL)
    {
        *cmd = new_cmd;
        head = *cmd;
    }
    else
    {
        head = *cmd;
        while ((*cmd)->next != NULL)
        {
            *cmd = (*cmd)->next;
        }
        (*cmd)->next = new_cmd;
    }
    return (head);
}

void set_path(t_cmd **cmd, char **argv, char **envp)
{
    int envp_idx;
    int cmd_idx;
    char *envp_str;
    int i;
    int start_idx;
    int end_idx;

    i = 0;
    cmd_idx = 2;
    envp_idx = find_path(envp);
    printf("path : %s\n", envp[envp_idx]);
    while (envp_idx != -1 && argv[cmd_idx + 1] != NULL)
    {
        while (envp[envp_idx][i] != '/')
            i++;
        start_idx = i;
        while (envp[envp_idx][i] != ':')
            i++;
        end_idx = i;
        envp_str = path_str(envp[envp_idx], start_idx, end_idx);
        char *tmp;
        tmp = envp_str;
        envp_str = ft_strjoin(tmp, argv[cmd_idx]);
        free(tmp);
        if (argv[cmd_idx + 1][0] == '-')
        {
            cmd_idx++;
            tmp = envp_str;
            envp_str = ft_strjoin(tmp, argv[cmd_idx]);
            free(tmp);
        }
        tmp = NULL;
        printf("envp_str : %s\n", envp_str);
        if (access(envp_str, F_OK | X_OK) == 0)
        {
            printf("find path\n");
            *cmd = link_cmd(cmd, envp_str);
            cmd_idx++;
            i = 0;
        }
        else
            free(envp_str);
    }
}

void free_cmd(t_cmd **cmd)
{
    t_cmd *tmp;

    while ((*cmd) != NULL)
    {
        tmp = (*cmd)->next;
        free((*cmd)->cmd_str);
        (*cmd)->cmd_str = '\0';
        free(*cmd);
        *cmd = tmp;
    }
    *cmd = NULL;
}

int main(int argc, char *argv[], char *envp[])
{
    t_cmd *cmd;

    cmd = NULL;
    printf("argc : %d\n", argc);
    print_argv(argv);
    // char *stuff[3];
    // stuff[0] = "/bin/ls";
    // stuff[1] = "-l";
    // stuff[2] = NULL;
    // execve(stuff[0], stuff, NULL);
    if (argc > 4)
    {
        if (access(argv[1], F_OK) == -1)
            printf("file1이 존재하지 않음\n");
        else
        {
            set_path(&cmd, argv, envp);
            free_cmd(&cmd);
        }
    }
    else
        printf("usage : ./pipex file1 cmd1 cmd2 file2\n");
    return (0);
}