#include "my_shell.h"

/**
 * ft_getpath - search the path the commend
 * @cmd: commend
 *
 * Return: path_name is found or NULL is does found
 */

char *ft_getpath(char *cmd)
{
	char *path;
	char *path_name;
	char *tmp;
	struct stat st;
	int i = 0;

	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (ft_strdup(cmd));
			return (NULL);
		}
		i++;
	}
	path = ft_getenv("PATH");
	if (!path)
		return (NULL);
	tmp = strtok(path, ":");
	while (tmp)
	{
		path_name = (char *)malloc(ft_strlen(tmp) + ft_strlen(cmd) + 2);
		if (!path_name)
			break;
		ft_strcpy(path_name, tmp);
		ft_strcat(path_name, "/");
		ft_strcat(path_name, cmd);
		if (stat(path_name, &st) == 0)
		{
			free(path);
			return (path_name);
		}
		free(path_name);
		tmp = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
