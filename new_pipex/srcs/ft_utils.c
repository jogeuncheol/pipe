#include "../include/pipex.h"

char	*ft_cut_str(char *str)
{
	int		i;
	int		j;
	char	*cut_cmd;

	j = 0;
	while (str[j] == ' ')
		j++;
	i = j;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	cut_cmd = malloc((i + 1) * sizeof(char));
	if (cut_cmd == NULL)
		return (NULL);
	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		cut_cmd[i] = str[i];
		i++;
	}
	cut_cmd[i] = '\0';
	return (cut_cmd);
}

char	*ft_cut_str_single_q(char *str)
{
	int		i;
	char	*cut_cmd;

	i = 0;
	while (str[i + 1] != '\'')
		i++;
	cut_cmd = malloc((i + 1) * sizeof(char));
	if (cut_cmd == NULL)
		return (NULL);
	i = 0;
	while (str[i + 1] != '\'' && str[i] != '\0')
	{
		cut_cmd[i] = str[i + 1];
		i++;
	}
	cut_cmd[i] = '\0';
	return (cut_cmd);
}

int	ft_find_sp(char	*str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
