#include "my_shell.h"

/**
 * displaye_error - print error if commend doesn't exist
 * @name: name the programme
 * @cmd: commend
 * @index: index to commend
 * Return: nothing
 */

void displaye_error(char *name, char *cmd, int index)
{
	char *idx = ft_itoa(index);

	write(STDERR_FILENO, name, ft_strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, ft_strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, ft_strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
	free(idx);
}
