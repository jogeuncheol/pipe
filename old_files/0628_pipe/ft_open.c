#include "pipex.h"

int ft_open(int idx, char **argv, char ***cmd_arr, int file1_fd)
{
	int fd;

	if (idx == 1)
		fd = open(argv[idx], O_RDONLY);
	else
		fd = open(argv[idx], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		if (idx != 1)
			close(file1_fd);
		ft_error_fn(NULL, cmd_arr, NULL);
	}
	return (fd);
}