#include "my_shell.h"

/**
 * ft_execute - execute the programme
 * @cmds: commends
 * @argv: argement
 * @idx: index the commend
 *
 * Return: status
 */

int ft_execute(char **cmds, char **argv, int idx)
{
	char	*path_name;
	pid_t	pid;
	int	status;

	if (!cmds[0] || cmds[0][0] == '\0')
	{
		free_arrays(cmds);
		return (0);
	}
	path_name = ft_getpath(cmds[0]);
	if (!path_name)
	{
		displaye_error(argv[0], cmds[0], idx);
		free_arrays(cmds);
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(path_name, cmds, environ) == -1)
		{
			free(path_name);
			free_arrays(cmds);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		status = WEXITSTATUS(status);
		free_arrays(cmds);
		free(path_name);
	}
	return (status);
}
