#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void ft_exec(int i, char **envp)
{
	char *stuff[2];

	if (i == 0)
		stuff[0] = "/bin/ls";
	if (i == 1)
		stuff[0] = "/bin/pwd";
	if (i == 2)
		stuff[0] = "/usr/bin/wc";
	stuff[1] = NULL;
	execve(stuff[0], stuff, envp);
}

int main(int argc, char *argv[], char *envp[])
{
	pid_t pid;
	int fd[2];
	int i = 0;

	pipe(fd);
	while (i < 3)
	{
	pid = fork();
	if (pid == 0)
	{
		printf("==== hello child ====\n");
		printf("fd[0] : %d, fd[1] : %d\n", fd[0], fd[1]);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		ft_exec(i, envp);
	}
	else
	{
		wait(0);
		printf("==== hello parent ====\n");
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
	}
	i = i + 2;
	}
//	close(fd[1]);
}
