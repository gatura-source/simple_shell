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

	for (i = 0; inp[i] != NULL; i++)
	{
		free(inp[i]);
	}
	free(inp);
}
