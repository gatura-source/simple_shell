#include "shell.h"
#include <string.h>

/**
 * count_tokens - counts whitespace-separated tokens
 * @input: input string
 *
 * Return: number of tokens; 0 if none
 */
static size_t count_tokens(char *input)
{
	size_t count;
	int in_token;

	count = 0;
	in_token = 0;
	while (*input != '\0')
	{
		if (_isspace(*input))
		{
			in_token = 0;
		}
		else if (!in_token)
		{
			in_token = 1;
			count++;
		}
		input++;
	}
	return (count);
}

/**
 * get_tokens - splits input into a NULL-terminated array of duplicated tokens
 * @input: input string
 *
 * Return: allocated array on success, or NULL
 */
char **get_tokens(char *input)
{
	char **args;
	char *token;
	size_t count;
	size_t i;
	char *copy;

	if (input == NULL || *input == '\0')
	{
		return (NULL);
	}
	count = count_tokens(input);
	if (count == 0)
	{
		return (NULL);
	}
	args = (char **)err_malloc(sizeof(char *) * (count + 1));
	if (args == NULL)
	{
		return (NULL);
	}
	token = strtok(input, " ");
	for (i = 0; i < count && token != NULL; i++)
	{
		copy = _strdup(token);
		if (copy == NULL)
		{
			free_tokens(args);
			return (NULL);
		}
		args[i] = copy;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}
