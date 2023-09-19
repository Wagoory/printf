#include "main.h"

/**
 * get_flag - get the specific flag
 * @s: character pointer
 * @f: pointer
 * Return: length of format
 */
int get_flag(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
		case '-':
			f->minus = 1;
			i = 1;
			break;
	}

	return (i);
}
