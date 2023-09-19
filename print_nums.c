#include "main.h"

/**
 * print_integer - prints an integer
 * @prf: list of arg
 * @f: pointer to flag
 * Return: length of format
 */
int print_integer(va_list prf, flags_t *f)
{
	int num = va_arg(prf, int);
	int result = cnt_digit(num);

	if (f->space == 1 && f->plus == 0 && num >= 0)
		result += _putchar(' ');
	if (f->plus == 1 && num >= 0)
		result += _putchar('+');
	if (f->minus == 1 && num <= 0)
		result += _putchar('-');
	if (num <= 0)
		result++;
	print_number(num);
	return (result);
}

/**
 * print_unsigned - prints unsigned int
 * @prf: list of arg
 * @f: pointer to flags
 * Return: length of format
 */
int print_unsigned(va_list prf, flags_t *f)
{
	unsigned int un = va_arg(prf, unsigned int);
	char *s = convert(un, 10, 0);

	(void)f;
	return (_puts(s));
}

/**
 * print_number - ptints num
 * @num: integer to be printed
 */
void print_number(int num)
{
	unsigned int num1;

	if (num < 0)
	{
		_putchar('-');
		num1 = -num;
	}
	else
		num1 = num;

	if (num1 / 10)
		print_number(num1 / 10);
	_putchar((num1 % 10) + '0');
}

/**
 * cnt_digit - prints digit
 * @i: int
 * Return: length of format
 */
int cnt_digit(int i)
{
	unsigned int dig = 0;
	unsigned int un;

	if (i < 0)
		un = i * -1;
	else
		un = i;
	while (un != 0)
	{
		un /= 10;
		dig++;
	}
	return (dig);
}
