#ifndef _MAIN_H
#define _MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/* print_nums */
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* print_bases */
int print_hex(va_list prf, flags_t *f);
int print_hex_big(va_list prf, flags_t *f);
int print_binary(va_list prf, flags_t *f);
int print_octal(va_list prf, flags_t *f);

/* converter */
char *convert(unsigned long int n, int base, int lower);

/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char s))(va_list, flags_t *);

/* get_flag */
int get_flag(char s, flags_t *f);

/* print_alpha */
int print_string(va_list prf, flags_t *f);
int print_char(va_list prf, flags_t *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_rot13(va_list prf, flags_t *f);
int print_rev(va_list prf, flags_t *f);
int print_non(va_list prf, flags_t *f);

/* print_address */
int print_address(va_list prf, flags_t *f);

/* print_percent */
int print_per(va_list prf, flags_t *f);

#endif
