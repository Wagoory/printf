#include "main.h"

/**
 * convert - convert a number
 * @n: input number
 * @base: base
 * @lower: lower hexadecimal
 * Return: length of format
 */
char *convert(unsigned long int n, int base, int lower)
{
	static char *rep;
	static char buffer[50];
	char *p;

	rep = (lower)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';
	do {
		*--p = rep[n % base];
		n /= base;
	} while (n != 0);

	return (p);
}
