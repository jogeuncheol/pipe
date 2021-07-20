#include <stdio.h>
#include "pipex.h"

void set_pipe_struct(t_pipe *pip, int file1_fd)
{
	pip->cmd_idx = 1000042;
	pip->backup_fd = file1_fd;
	pip->fd[0] = 0;
	pip->fd[1] = 0;
}

int main()
{
    t_pipe pip;

    set_pipe_struct(&pip, 0);
    printf("pip.cmd_idx : %d\n", pip.cmd_idx);
    pip.cmd_idx++;
    printf("pip.cmd_idx : %d\n", pip.cmd_idx);
}