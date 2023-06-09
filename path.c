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
	char command_path[MAX_INPUT_SIZE];
	char *path_copy;
	int found = 0;

	if (args == NULL || args[0] == NULL)
	{
		printf("Invalid");
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
		}
		dir = strtok(path, ":");

		while (dir != NULL)
		{
		/* command_path_s = _strlen(dir) + _strlen(args[0]) + 2; */
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
		return;
	}
	path_exe(args);
}
/**
 * path_exe - a function to execute command
 * @args: array of arguments
 *
 * Return: Nothing
 */
void path_exe(char **args)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		execve(args[1], args, NULL);
		perror("Execution failed");
		exit(1);
	}
	else
	{
		int status;
		pid_t wpid;

		do {
			wpid = waitpid(pid, &status, 0);
			if (wpid == -1)
			{
				perror("Waitpid failed");
				exit(1);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
