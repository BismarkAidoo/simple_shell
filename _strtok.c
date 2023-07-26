#include "shell.h"

/**
 * _strtok - breaks the input line and creates tokens.
 * @str: pointer to line of af strings to break.
 * @delim: pointer to the token separator.
 * Return: array of individual words from an input line.
*/
char *_strtok(char *str, char *delim)
{
	static char *input_line, words_array[64][20];
	static int word_count;
	char *ptr_start, *ptr_end;
	int len;

	if (str != NULL)
	{
		input_line = str;
		word_count = 0;
	}

	if (input_line == NULL)
		return (NULL);

	ptr_start = input_line;
	ptr_end = strstr(input_line, delim);

	if (ptr_end == NULL)
		ptr_end = input_line + strlen(input_line);

	len = ptr_end - ptr_start;
	strncpy(words_array[word_count], ptr_start, len);
	words_array[word_count][len] = '\0';
	word_count++;

	if (word_count == 64)
		return (NULL);

	if (*ptr_end == '\0')
		input_line = NULL;
	else
		input_line = ptr_end + strlen(delim);

	return (words_array[word_count - 1]);
}
