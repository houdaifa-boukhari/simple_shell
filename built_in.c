#include "my_shell.h"

/**
 * built_in - cheack is builtin or not
 * @cmd: commend
 *
 * Return: 1 is true or 0 or false
 */

int built_in(char *cmd)
{
	char *sp_cmd[] = {"exit", "env", NULL};
	int i = 0;

	if (!cmd || cmd[0] == '\0')
		return (0);
	while (sp_cmd[i])
	{
		if (ft_strcmp(cmd, sp_cmd[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * handle_cmd - handle commend
 * @cmd: commend
 * @status: status
 *
 * Return: nothing
 */

void handle_cmd(char **cmd, int *status)
{
	if (ft_strcmp(cmd[0], "exit") == 0)
		ft_exit(cmd, status);
	else if (ft_strcmp(cmd[0], "env") == 0)
		displaye_env(cmd, status);
}

/**
 * displaye_env - print all environ
 * @cmd: commends
 * @status: status
 *
 * Return: nothing
 */

void displaye_env(char **cmd, int *status)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], ft_strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	*status = 0;
	free_arrays(cmd);
}

/**
 * ft_exit - exit in own shell
 * @cmd: commens
 * @status: status
 *
 * Return: nothing
 */

void ft_exit(char **cmd, int *status)
{
	free_arrays(cmd);
	exit(*status);
}
