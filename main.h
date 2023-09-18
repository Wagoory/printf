#ifndef _MAIN_H
#define _MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct flag
 * @plus: '+'
 * @space: ' '
 * @hash: '#'
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct Handler - struct to handle
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct Handler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/* print_nums */
int print_integer(va_list prf, flags_t *f);
void print_number(int num);
int print_unsigned(va_list prf, flags_t *f);
int cnt_digit(int i);

/* print_bases */
int print_hexadec(va_list prf, flags_t *f);
int print_hexadec_upper(va_list prf, flags_t *f);
int print_bin(va_list prf, flags_t *f);
int print_octal(va_list prf, flags_t *f);

/* converter */
char *convert(unsigned long int n, int base, int lower);

/* _printf */
int _printf(const char *format, ...);
int (*get_print(char s))(va_list, flags_t *);
int get_flag(char s, flags_t *f);

/* print_alpha */
int print_str(va_list prf, flags_t *f);
int print_ch(va_list prf, flags_t *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_rot13(va_list prf, flags_t *f);
int print_rev(va_list prf, flags_t *f);
int print_non(va_list prf, flags_t *f);

/* print */
int print_addr(va_list prf, flags_t *f);
int print_per(va_list prf, flags_t *f);

#endif
