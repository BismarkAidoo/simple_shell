#include "shell.h"

/**
 * concat_path - concatinate the path name with command name to
 * create an absolute pathname.
 * @abs_path_name: double pointer to the final absolute pathname
 * @cpy_filename: double pointer to the current path to search for the
 * file existance.
 * @cmdname: double pointer to the command name.
 * Return: nothing.
 */
void concat_path(char **abs_path_name, char **cpy_filename, char **cmdname)
{
	*abs_path_name = (char *)malloc(sizeof(char) *
			(strlen(*cpy_filename) + strlen(*cmdname) + 2));
	strcpy(*abs_path_name, *cpy_filename);
	strcat(*abs_path_name, "/");
	strcat(*abs_path_name, *cmdname);
}

/**
 * search_path_and_create - creates an absolute pathname for a command
 * @cmdname: command name to create the filename
 * Return: pointer to the filename.
 */
char *search_path_and_create(char *cmdname)
{
	char *cpy_filename, *path, *cpy_path, *abs_path_name;

	if (cmdname == NULL || *cmdname == '\0')
		return (NULL);

	if (access(cmdname, X_OK) == 0)
	{
		cpy_filename = (char *)malloc(sizeof(char) * (strlen(cmdname) + 1));
		if (cpy_filename == NULL)
			return (NULL);
		strcpy(cpy_filename, cmdname);
		return (cpy_filename);
	}
	else
	{
		path = get_environ_value("PATH");
		cpy_path = (char *)malloc(sizeof(char) * (strlen(path) + 1));
		if (cpy_path == NULL)
			return (NULL);
		strcpy(cpy_path, path);
		cpy_filename = _strtok(cpy_path, ":");

		while (cpy_filename != NULL)
		{
			concat_path(&abs_path_name, &cpy_filename, &cmdname);
			if (access(abs_path_name, X_OK) == 0)
			{
				free(cpy_path);
				return (abs_path_name);
			}
			else
			{
				free(abs_path_name);
				abs_path_name = NULL;
			}
			cpy_filename = _strtok(NULL, ":");
		}
	}
	free(cpy_path);
	return (NULL);
}

/**
 * line_break_down - breaks down the input line and assigns the corresponding
 * value to the shell_cmd members.
 * @cmd: double pointer to the command bucket in the shell_cmd data structure
 * @args: pointer to the bucket or arrarys of strings
 * @line: pointer ot the user input line.
 * Return: nothing
 */
void line_break_down(char **cmd, char **args[], char *line)
{
	char *word, *cpy_word;
	int idx = 1, n = 0;

	word = _strtok(line, " ");
	while (word != NULL)
	{
		n = strlen(word);
		if (n > 0)
		{
			cpy_word = (char *)malloc(sizeof(char) * (strlen(word) + 1));
			strcpy(cpy_word, word);
			if (*cmd == NULL)
			{
				*cmd = cpy_word;
				(*args)[0] = cpy_word;
			}
			else
			{
				if (idx < 20)
				{
					(*args)[idx] = cpy_word;
					idx++;
				}
			}
		}
		word = _strtok(NULL, " ");
	}
	(*args)[idx] = NULL;
}

/**
 * create_command_buf - create a node with command and argument field for
 * the shell.
 * @head: double to the head node of the node structure.
 * @line: pointer to the input line containg instruction.
 * Return: pointer to the new node or data field.
 */
shell_cmd *create_command_buf(shell_cmd **head, char *line)
{
	shell_cmd *new_node;
	int i = 0;

	new_node = (shell_cmd *)malloc(sizeof(shell_cmd));
	if (new_node == NULL)
		return (NULL);

	new_node->args = (char **)malloc(sizeof(char *) * 20);
	if (new_node->args == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->command = NULL;
	while (i < 20)
		new_node->args[i++] = NULL;

	line_break_down(&new_node->command, &new_node->args, line);

	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}

	return (new_node);
}
