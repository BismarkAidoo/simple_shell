#include "shell.h"

/**
 * print_environment - afunction that prints the environment variable
 *
 * Return: Nothing
 */
void print_environment()
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n," *env);
		env++;
	}
}
/**
 * handle_path - a function that handle the path ot an argument
 * @comand: command entered bu user
 * @arguments
 *
 * Return: Nothinmg
 */
void handle_path(char *command, char *arguments[])
{
	char *path;
	char *path_token;
	char command_path[MAX_COMMAND_LENGTH];

	path = _getenv("PATH");
	if (path == NULL)
	{
		printf("Command not found: %s\n", command);
		return;
	 }
	 /* tokenize the PATH variable */
	path_token = strtok(path, ":");
	whiel (path_token != NULL)
	{
		snprintf(command_path, sizeof(command_path) "%s/%s"path_name, command);
		 /* Check if command exists in the current */
		if (access(command_path, X_OK) == o)
		{
			if (fork() == 0)
			{
				execvp(command_path, arguments);
				exit(0);
			}
			else
			{
				wait(null)
			}
			return;
		}
		path_token = strtok(NULL, ";");
	}
