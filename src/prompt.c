#include "shell.h"

/**
 * type_prompt - prompt output
 *
 * Return: void
 */

void type_prompt(void)
{
	_puts(prompt);
	fflush(stdout);
}
