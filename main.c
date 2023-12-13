#include "my_shell.h"

/**
 * main - own shell
 * @argc: number argument
 * @argv: string of argument
 *
 * Return: status
 */

int main(int argc, char **argv)
{
	int status;
	int idx;
	char **commends;
	char *line;

	(void)argc;
	line = NULL;
	commends = NULL;
	status = 0;
	idx = 0;
	while (1)
	{
		line = ft_getline();
		if (!line)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		idx++;
		commends = ft_split(line);
		if (commends)
		{
			if (built_in(commends[0]))
				handle_cmd(commends, &status);
			else
				status = ft_execute(commends, argv, idx);
		}
	}
}
