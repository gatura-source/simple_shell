#include "shell.h"

/**
 * free_tokens - frees pointer to pointers
 * @inp: input pointer
 *
 *
 * Return: 0
 */

void free_tokens(char **inp)
{
	int i;

	i = 0;
	while (inp[i] != NULL)
	{
		free(inp[i]);
		i++;
	}
	free(inp);
}
