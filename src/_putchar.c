#include "shell.h"

/**
 * _putchar - like std putchar
 * @c: char input
 *
 * Return: charcters writen
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
