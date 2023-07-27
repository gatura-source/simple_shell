#include "shell.h"

/**
 * get_tokens - gets parameters;
 * @input: input string
 *
 * Return: **pointer
 */

char **get_tokens(char *input)
{
	char **args;
	int counter;
	char *token;
	char delimiters[] = " ";

	if (*input == '\0' || input  == NULL)
	{
		return (NULL);
	}
	counter = 0;
	args = (char **)err_malloc(sizeof(char *) * (_strlen(input) + 1));
	token = strtok(input, delimiters);
	while (token != NULL)
	{
		args[counter] = token;
		counter++;
		token = strtok(NULL, delimiters);
	}
	if (counter == 0)
	{
		free(args);
		return (NULL);
	}
	args[counter] = NULL;
	return (args);
}
