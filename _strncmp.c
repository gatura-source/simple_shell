#include "shell.h"

/**
 * _strncmp - like std strncmp
 * @str1: str1
 * @str2: str2
 * @len: len
 *
 * Description: works like strncmp
 *
 * Return: 0 or 1
 */

int _strncmp(char *str1, char *str2, size_t len)
{
	size_t i;

	for (i = 0; i < len; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[2]);
		}
		if (str1[i] == '\0' || str2[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
