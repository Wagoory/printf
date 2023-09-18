#include "main.h"

/**
 * print_hexadec - prints in hexadecimal format
 * @prf: list arg
 * @f: pointer to flags
 * Return: length of format
 */
int print_hexadec(va_list prf, flags_t *f)
{
	unsigned int num = va_arg(prf, unsigned int);
	char *s = convert(num, 16, 1);
	int cnt = 0;

	if (f->hash == 1 && s[0] != '0')
		cnt += _puts("0x");
	cnt += _puts(s);
	return (cnt);
}

/**
 * print_hexadec_upper - prints in hexadecimal format
 * @l: list of arg
 * @f: pointer to flag
 * Return: length of format 
 */
int print_hexadec_upper(va_list prf, flags_t *f)
{
	unsigned int num = va_arg(prf, unsigned int);
	char *s = convert(num, 16, 0);
	int cnt = 0;

	if (f->hash == 1 && s[0] != '0')
		cnt += _puts("0X");
	cnt += _puts(s);
	return (cnt);
}

/**
 * print_bin - prints a number in base 2
 * @prf: list of arg
 * @f: pointer to flag
 * Return: length of format
 */
int print_bin(va_list prf, flags_t *f)
{
	unsigned int num = va_arg(prf, unsigned int);
	char *s = convert(num, 2, 0);

	(void)f;
	return (_puts(s));
}

/**
 * print_octal - prints a number in base 8
 * @prf: list arg
 * @f: pointer to flag
 * Return: length of format
 */
int print_octal(va_list prf, flags_t *f)
{
	unsigned int num = va_arg(prf, unsigned int);
	char *s = convert(num, 8, 0);
	int cnt = 0;

	if (f->hash == 1 && s[0] != '0')
		cnt += _putchar('0');
	cnt += _puts(s);
	return (cnt);
}
