#include "my_shell.h"

/**
 * ft_strlen - calcule the length of a string
 * @str: The string to be calculate lenght
 *
 * Return: The length of the string.
 */

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * ft_strcpy - Copies a string
 * @dest: The destination buffer where the string will be copied
 * @src: The source string to be copied
 *
 * Return: A pointer to the dest
 */

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * ft_strdup - Duplicates a string
 * @src: The string to be duplicated
 *
 * Return: A pointer to the duplicated string,
 */

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t		i;

	if (src == NULL)
		return (NULL);
	i = ft_strlen(src) + 1;
	dest = (char *)malloc(sizeof(char) * i);
	if (dest != NULL)
		ft_strcpy(dest, src);
	return (dest);
}

/**
 * ft_strcmp - Compares two strings
 * @s1: The first string to be compared
 * @s2: The second string to be compared
 *
 * Return: s1 - s2
 */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

/**
 * ft_strcat - Concatenates two strings
 * @dest: The destination string to which the source will be appended
 * @src: The source string that will be appended to the destination
 *
 * Return: apointer to the resulting string dest
 */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
