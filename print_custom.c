#include "main.h"

/**
 * print_non - Non printable character
 * @prf: list of arg
 * @f: pointer
 * Return: length of format
 */
int print_non(va_list prf, flags_t *f)
{
	int i, cnt = 0;
	char *result;
	char *s = va_arg(prf, char *);

	(void)f;
	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			cnt += 2;
			result = convert(s[i], 16, 0);
			if (!result[1])
				cnt += _putchar('0');
			cnt += _puts(result);
		}
		else
			cnt += _putchar(s[i]);
	}
	return (cnt);
}

/**
 * print_rev - prints a string in reverse
 * @prf: list of arg
 * @f: pointer
 * Return: length format
 */
int print_rev(va_list prf, flags_t *f)
{
	int i, j;
	char *s = va_arg(prf, char *);

	(void)f;
	if (!s)
		s = "(null)";

	for (i; s[i]; i++)
		;

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);

	return (i);
}

/**
 * print_rot13 - prints a string using rot13
 * @prf: list of arg
 * @f: pointer
 * Return: length of format
 */
int print_rot13(va_list prf, flags_t *f)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(prf, char *);

	(void)f;
	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			_putchar(s[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (s[j] == rot13[i])
					_putchar(ROT13[i]);
			}
		}
	}

	return (j);
}

/**
 * print_per - prints a percent
 * @prf: list of arg
 * @f: pointer
 * Return: length of format
 */
int print_per(va_list prf, flags_t *f)
{
	(void)prf;
	(void)f;
	return (_putchar('%'));
}
