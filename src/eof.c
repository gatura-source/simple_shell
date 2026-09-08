#include "shell.h"


/**
 * eof - handles EOF
 * @input: input string
 *
 * Return: string ptr
 */

char *eof(char *input)
{
	if (input == NULL || *input == '\0' || check_spaces(input))
	{
		return (NULL);
	}
	input[_strcspn(input, "\n")] = '\0';
	return (input);
}



