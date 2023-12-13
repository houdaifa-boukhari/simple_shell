#include "my_shell.h"

#define delim " \t\n"

/**
 * count_words - calcul nunbers the words of string
 * @str: commens
 *
 * Return: number the word
 */

int count_words(char *str)
{
	int count;
	char *ptr = ft_strdup(str);
	char *ptr1 = ptr;

	count = 0;
	ptr = strtok(ptr, delim);
	while (ptr)
	{
		count++;
		ptr = strtok(NULL, delim);
	}
	free(ptr1);
	return (count);
}

/**
 * alocate_split - allocation new str
 * @str: commend
 * @new_str: 2d arrays to stok commends
 *
 * Return: new_str
 */

char **alocate_split(char *str, char **new_str)
{
	int i;
	char *ptr = ft_strdup(str);
	char *ptr1 = ptr;

	i = 0;
	ptr = strtok(ptr, delim);
	while (ptr)
	{
		new_str[i] = ft_strdup(ptr);
		ptr = strtok(NULL, delim);
		i++;
	}
	new_str[i] = NULL;
	free(ptr1);
	return (new_str);
}

/**
 * ft_split - split commend by delim
 * @line : commend by line
 *
 * Return: new commende by split
 */

char **ft_split(char *line)
{
	char **str;
	int nbr_words;

	if (!line)
		return (NULL);
	nbr_words = count_words(line);
	str = (char **)malloc(sizeof(char *) * (nbr_words + 1));
	if (!str)
		return (NULL);
	str = alocate_split(line, str);
	if (!str)
		return (NULL);
	free(line);
	return (str);
}
