#include "shell.h"

/**
 * err_malloc - error-checked malloc
 * @memsize: size to be allocated
 *
 * Return: NULL if fail  or pointer to allocated mem
 */

void *err_malloc(unsigned int memsize)
{
	void *ptr;

	ptr = malloc(memsize);
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}
