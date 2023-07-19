#include "shell.h"

/**
 * _strchr - like strchr
 * @pstring: parent string
 * @needle: needle
 *
 * Return: pointer to the first occurence of needle
 */

char *_strchr(const char *pstring, int needle)
{
	while (*pstring != '\0')
	{
		if (*pstring == (char)needle)
		{
			return ((char *)pstring);
		}
		pstring++;
	}
	return (NULL);
}
