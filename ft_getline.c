#include "my_shell.h"

/**
 * ft_getline - read line in input
 *
 * Return: line if not null
 */

void *ft_getline()
{
	char *line;
	size_t len;

	line = NULL;
	len = 0;
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	if (getline(&line, &len, stdin) == -1 || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
