#include "shell.h"

/**
 * leading_space - removes extra space characters
 * @buffer: double pointer to the location reading characters from
 * @line: pointer to the location writing the cleaned characters
 * @size: number of bytes read from input.
 * Return: void
 */

int leading_space(char **buffer, char *line, int size)
{
	int i = 0, n, count;

	for (i = 0; i < size; i++)
		if ((*buffer)[i] != ' ' && (*buffer)[i] != '\0')
			break;

	if ((*buffer)[i] == '\0')
	{
		return (0);
	}
	for (n = 0; (*buffer)[i] != '\0'; n++)
	{
		if ((*buffer)[i] == ' ')
		{
			if ((*buffer)[i + 1] == ' ')
			{
				line[n] = (*buffer)[i];
				for (count = i + 1; (*buffer)[count] != '\0'; count++)
				{
					if ((*buffer)[count] != ' ')
					{
						n++;
						break;
					}
				}
				i = count;
				line[n] = (*buffer)[i];
			}
		}
		line[n] = (*buffer)[i];
		i++;
	}
	line[n] = '\0';
	return (strlen(line));
}

/**
 * _read_user_input - reads input from the command line.
 * @line: pointer to an array to hold thinput line.
 * Return: number of bytes read or -1 on failure.
 */

int _read_user_input(char *line)
{
	char character = '\0', *buffer;
	int i = 0, bytes;
	int char_read, size = 10;

	buffer = (char *)malloc(sizeof(char) * size);
	_memset(buffer, 0, sizeof(char) * size);
	while (character != EOF && character != 10)
	{
		char_read = read(STDIN_FILENO, &character, 1);
		if (char_read < 0)
		{
			free(buffer);
			return (0);
		}
		if (char_read == 0)
		{
			free(buffer);
			return (-1);

		}
		if (i >= size)
		{
			size += 5;
			buffer = realloc(buffer, size);
			_memset(buffer + i, 0, sizeof(char) * 5);
		}
		if (character != 10)
		{
			buffer[i] = character;
			i++;
		}
		else
			break;
	}
	buffer[i] = '\0';
	bytes = leading_space(&buffer, line, i);
	free(buffer);
	return (bytes);
}

/**
 * _memset - used to set a block of memory with a particular value.
 * @s: a pointer to the block of memory to be set.
 * @value: is the value to which each byte in the block will be set.
 * @num: is the number of bytes to be set.
 * Return: a pointer to the block pf memory set.
 */
char *_memset(char *s, char value, unsigned int num)
{
	unsigned int i = 0;

	while (i < num)
	{
		*(s + i) = value;
		i++;
	}
	return (s);
}
