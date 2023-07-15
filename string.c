#include "shell.h"

/**
 * _strcpy - like strcpy()
 * @dest: destination
 * @src: source
 *
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	size_t i;

	for (i = 0; i < _strlen(src); i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * _strlen - like strlen()
 * @str: string input
 *
 * Return: strlen()
 */

size_t _strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strncat - like strncat()
 * @str1: string input
 * @str2: string input
 * @len: length to copied
 *
 * Return: 0
 */

char *_strncat(char *str1, const char *str2, int len)
{
	size_t len2;
	size_t str1len;

	str1len = _strlen(str1);
	len2 = 0;
	while (len2 < (size_t) len && str2[len2] != '\0')
	{
		str1[str1len + len2] = str2[len2];
		len2++;
	}
	str1[str1len + len2] = '\0';
	return (str1);
}
/**
 * _puts - like puts()
 * @str: string input
 *
 * Return: len(str)
 */

int _puts(const char *str)
{
	int strlen;

	strlen = 0;
	while (str[strlen] != '\0')
	{
		strlen += _putchar(str[strlen]);
	}
	return (strlen);
}

/**
 * _strcspn - like strcspn()
 * @string: string input
 * @delimiters: set of delimiters
 *
 * Return: size_t where the first delimiter is encountered
 */

size_t _strcspn(const char *string, const char *delimiters)
{
	const char *strcopy;
	size_t count;
	const char *delimiterscopy;
	size_t tempcount;

	strcopy = string;
	count = 0;
	while (*strcopy)
	{
		delimiterscopy  = delimiters;
		tempcount = count;
		while (*delimiterscopy)
		{
			if (*strcopy == *delimiterscopy)
			{
				return (tempcount);
			}
			delimiterscopy++;
		}
		strcopy++;
		count++;
	}
	return (count);
}
