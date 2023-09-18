#include "main.h"

/**
 * _printf - format output
 * @format: format string
 * Return: length of the format
 */
int _printf(const char *format, ...)
{
	int (*pf)(va_list, flags_t *);
	const char *p;
	va_list prf;
	flags_t flags = {0, 0, 0};

	register int cnt = 0;

	va_start(prf, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				cnt += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pf = get_print(*p);
			cnt += (pf)
				? pf(prf, &flags)
				: _printf("%%%c", *p);
		} else
			cnt += _putchar(*p);
	}
	_putchar(-1);
	va_end(prf);
	return (cnt);
}
