#include "shell.h"
#include <string.h>

void path_exe(char **args);
/**
 * handle_path - a function that handle the path given in an environment
 * @args: array to pass to function
 * @path: pointer to the path
 *
 * Return: Nothing
 */

void handle_path(char **args, char *path)
{
	char *dir;
	char *path_copy;
	char command_path[MAX_INPUT_SIZE];
	int found = 0;

	if (args == NULL || args[0] == NULL)
	{
		return;
	}

	if (args[0][0] == '/')
	{
		if (access(args[0], X_OK) == 0)
		{
			found = 1;
			_strcpy(command_path, args[0]);
		}
	}
	else
	{
		path_copy = strdup(path);
		if (path_copy == NULL)
		{
			perror("Memory allocation failed");
			return;
		{
		dir = strtok(path, ":");
		while (dir != NULL)
		{
			_strcpy(command_path, dir);
			_strcat(command_path, "/");
			_strcat(command_path, args[0]);
			if (access(command_path, X_OK) == 0)
			{
				found = 1;
				break;
			}
			dir = strtok(NULL, ":");
		}
	}
	if (!found)
	{
		printf("command not found: %s\n", command_path);
		return;
	}
	if (execve(command_path, args, NULL) == -1)
	{
		perror("Execution failed");
		exit(1);
	}
}
