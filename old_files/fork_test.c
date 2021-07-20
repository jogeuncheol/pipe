#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void ft_hello()
{
	printf("==== in ft_hello ====\n");
	printf("pid : %d\n", getpid());
	printf("ppid : %d\n", getppid());
	pid_t pid;

	int i = 0;
	int fd[2];
	while (i < 2)
	{
	pipe(fd);
	pid = fork();
	if (pid < 0)
		printf("fork error\n");
	else if (pid == 0)
	{
		printf("==== hello child ====\n");
		printf("pid : %d\n", getpid());
		printf("ppid : %d\n", getppid());
		printf("i : %d\n", i);
		char *stuff[3];
		stuff[0] = strdup("/bin/ls");
		stuff[1] = strdup("-l");;
		stuff[2] = NULL;
		execve(stuff[0], stuff, NULL);
	}
	else
	{
		wait(0);
//		printf("==== hello parent ====\n");
//		printf("pid : %d\n", getpid());
//		printf("ppid : %d\n", getppid());
	}
	i++;
	}
}

int main()
{
	printf("==== fork test program ====\n");
	ft_hello();
	return (0);
}
