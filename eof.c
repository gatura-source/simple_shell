#include "shell.h"


/**
 * eof - handles EOF
 * @input: input string
 *
 * Return: string ptr
 */

char *eof(char *input)
{
	input[_strcspn(input, "\n")] = '\0';
	return (input);
}



