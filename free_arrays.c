#include "my_shell.h"

/**
 * free_arrays - free 2D arrays
 * @str: 2D arrays
 *
 * Return: nothing
 */

void	free_arrays(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			str[i] = NULL;
			i++;
		}
		free(str);
		str = NULL;
	}
}
