/**
 * _memset - like memset
 * @str: string input
 * @chr: char to set mem
 * @mem_space: memspace to fill with ch
 *
 * Return: void
 */
#include "shell.h"

void *_memset(void *str, int chr, size_t mem_space)
{
	size_t i;
	unsigned char val;
	unsigned char *ptr;

	ptr = (unsigned char *)str;
	val = (unsigned char)chr;

	for (i = 0; i < mem_space; i++)
	{
		*ptr++ = val;
	}

	return (ptr);
}
