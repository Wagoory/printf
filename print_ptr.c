#include "main.h"

/**
 * print_addr - prints address
 * @prf: list of arg
 * @f: pointer
 * Return: length of format
 */
int print_addr(va_list prf, flags_t *f)
{
	char *string;
	unsigned long int ptr = va_arg(prf, unsigned long int);

	register int cnt = 0;

	(void)f;

	if (!ptr)
		return (_puts("(nil)"));
	string = convert(ptr, 16, 1);
	cnt += _puts("0x");
	cnt += _puts(string);
	return (cnt);
}
