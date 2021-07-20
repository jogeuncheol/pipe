#include "pipex.h"

t_cmd *creat_cmd(char *str, int count)
{
	t_cmd *new_node;
	
	new_node = (t_cmd *)malloc(sizeof(t_cmd));
	if (new_node == NULL)
		return (NULL);
	new_node->cmd_str = str;
	new_node->cmd_count = count;
	return (new_node);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (*(s + i) != (unsigned char)c)
	{
		if (*(s + i) == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

char *cut_argv(char *argv, int s_idx, int e_idx)
{
	char *str;
	int i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (e_idx - s_idx + 1));
	if (str == NULL)
		return (NULL);
	while (s_idx < e_idx)
	{
		str[i] = argv[s_idx];
		i++;
		s_idx++;
	}
	str[i] = '\0';
	return (str);
}

void spilt_argv(char **cmd_list, char *cmd, int count)
{
	int i;
	int s_idx;
	int e_idx;
	t_cmd *head;

	i = 0;
	head = *cmd_list;
	while (head->next != NULL)
		head = head->next;
	while (cmd[i] != '\0')
	{
		while (cmd[i] == ' ')
			i++;
		if (cmd[i] == '\0' && cmd[i - 1] == ' ')
			; // error
		s_idx = i;
		while (cmd[i] != ' ')
			i++;
		e_idx = i;
		head->next = creat_cmd(cut_argv(cmd, s_idx, e_idx), count);
		i++;
	}
}

t_cmd *set_cmd_list(cmd_list, char *cmd, int count)
{
	if (ft_strchr(cmd, ' ') != NULL)
	{
		
		split_argv(cmd_list, cmd, count);
	}
	else

}