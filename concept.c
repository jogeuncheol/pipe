#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

/*
 * loop over commands by sharing
 * pipes.
 */
static void
pipeline(char ***cmd, char **envp)
{
	int fd[2];
	pid_t pid;
	int fdd = 0;				/* Backup */

	int open_f = open("file2_new", O_RDWR | O_CREAT | O_TRUNC, 0644);

	while (*cmd != NULL) {
		pipe(fd);				/* Sharing bidiflow */
		if ((pid = fork()) == -1) {
			perror("fork");
			exit(1);
		}
		else if (pid == 0) {
			printf("child pid : %d\nchild ppid : %d\n", getpid(), getppid());
			dup2(fdd, 0);
			if (*(cmd + 1) != NULL) {
				dup2(fd[1], 1);
			}
			else
				dup2(open_f, 1);
			close(fd[0]);
			execve((*cmd)[0], *cmd, envp);
			exit(1);
		}
		else {
			wait(0); 		/* Collect childs */
			printf("parent pid : %d\nparent ppid : %d\n", getpid(), getppid());
			close(fd[1]);
			fdd = fd[0];
			cmd++;
		}
	}
}

/*
 * Compute multi-pipeline based
 * on a command list.
 */
int
main(int argc, char *argv[], char *envp[])
{
	char *ls[] = {"/bin/ls", "-al", NULL};
	char *rev[] = {"rev", NULL};
	char *nl[] = {"/usr/bin/nl", NULL};
	char *cat[] = {"/bin/cat", "-e", NULL};
	char *grep[] = {"/usr/bin/grep", "file", NULL};
	char **cmd[] = {ls, nl, cat, grep, NULL};

	pipeline(cmd, envp);
	return (0);
}
