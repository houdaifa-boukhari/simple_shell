#include "my_shell.h"

/**
 * ft_getenv - search valeur the var_env
 * @var_env: variable environ
 *
 * Return: valeur the var_env
 */

char *ft_getenv(char *var_env)
{
	char *variable;
	char *value;
	char *env_value;
	char *tmp;
	int i;

	i = 0;
	while (environ[i])
	{
		tmp = ft_strdup(environ[i]);
		variable = strtok(tmp, "=");
		if (ft_strcmp(variable, var_env) == 0)
		{
			value = strtok(NULL, "\n");
			env_value = ft_strdup(value);
			free(tmp);
			tmp = NULL;
			return (env_value);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}
