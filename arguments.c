#include "shell.h"
#include <string.h>

/**
 * handle_args - command to handle arguments
 * @input: input string to tokenize
 *
 * Return: Always (0) success
 */
char **handle_args(char *input)
{
	int ac = 0;
	int index = 0;
	char **args;
	char *token;

	token = strtok(input, " ");
	while (token != NULL)
	{
		ac++;
		token = strtok(NULL, " ");
	}
	args = malloc(sizeof(char *) * (ac + 1));
	token = strtok(input, " ");
	while (token != NULL)
	{
		args[index] = strdup(token);
		token = strtok(NULL, " ");
		index++;
	}
	args[index] = NULL;
	return (args);
}
