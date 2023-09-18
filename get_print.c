#include "main.h"

/**
 * get_print - select the printer
 * @s: character
 * Return: a pointer
 */
int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', print_integer},
		{'s', print_str},
		{'c', print_ch},
		{'d', print_integer},
		{'u', print_unsigned},
		{'x', print_hexadec},
		{'X', print_hexadec_upper},
		{'b', print_bin},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_non},
		{'p', print_addr},
		{'%', print_per}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
