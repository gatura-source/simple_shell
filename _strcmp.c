#include "shell.h"

/**
 * _strcmp - like strcmp()
 * @str1: string 1
 * @str2: string 2
 *
 * Return: 1 if a == b
 */

int _strcmp(char *str1, char *str2)
{
	size_t len1;
	size_t len2;
	size_t i;
	int ret;

	ret = 0;
	len1 = _strlen(str1);
	len2 = _strlen(str2);
	if (len1 != len2)
	{
		return (0);
	}
	for (i = 0; i < len1; i++)
	{
		if ((str1[i] - str2[i]) == 0)
		{
			ret = 1;
		}
		else
		{
			ret = 0;
		}
	}
	return (ret);
}


