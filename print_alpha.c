#include "main.h"

/**
 * print_str - print string
 * @prf: list arg
 * @f: pointer to flag
 * Return: length of format
 */
int print_str(va_list prf, flags_t *f)
{
	char *str = va_arg(prf, char *);

	(void)f;

	if (!str)
		str = "(null)";
	return (_puts(str));
}

/**
 * print_ch - prints a character
 * @prf: list arguments
 * @f: pointer to flag
 * Return: length of format
 */
int print_ch(va_list prf, flags_t *f)
{
	(void)f;
	_putchar(va_arg(prf, int));
	return (1);
}
