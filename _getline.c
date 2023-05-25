#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

ssize_t getline(char **lineptr,
		size_t *n, FILE *stream)
{
	static char static_buffer[BUFFER_SIZE];
	static size_t static_buffer_index;
	ssize_t characters_read = 0;

	if (static_buffer_index == 0 || static_buffer_index
		    == strlen(static_buffer))
	{
		size_t bytes_read = fread(static_buffer, 1,
				BUFFER_SIZE, stream);
		if (bytes_read == 0)
		{
			return (-1);
		}
		static_buffer_index = 0;
	}
	while (static_buffer_index > 0 &&
			static_buffer[static_buffer_index - 1] != '\n')
	{
		if (characters_read >= (ssize_t)(*n - 1))
		{
			*n += BUFFER_SIZE;
			*lineptr = realloc(*lineptr, *n);

			if (*lineptr == NULL)
			{
				return (-1);
			}
		}
		(*lineptr)[characters_read++] =
			static_buffer[--static_buffer_index];
	}
	if (static_buffer_index > 0 &&
			static_buffer[static_buffer_index - 1] == '\n')
	{
		(*lineptr)[characters_read++] =
			static_buffer[static_buffer_index - 1];
		static_buffer_index++;
		return (characters_read);
	}
	return (characters_read);
}
