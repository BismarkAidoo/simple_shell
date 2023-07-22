#include "shell.h"

/**
 * get_environ_value - function fetches requested enviroment
 * variable value
 * @env_variable: the path for the enviroment variable needed
 * Return: the path if successful or NULL if fail
 *
 */
char *get_environ_value(char *env_variable)
{
	size_t size = strlen(env_variable), pos = 0;

	if (env_variable == NULL || *env_variable == '\0')
	{
		return (NULL);
	}

	while (environ[pos] != NULL)
	{
		if (strncmp(env_variable, environ[pos], size) == 0 &&
				environ[pos][size] == '=')
		{
			return (&environ[pos][size + 1]);
		}
		pos++;
	}

	return (NULL);
}
