#ifndef HOLB_H
#define HOLB_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

#define FALSE 0
#define TRUE 1

#define LOW 2
#define CAP 3

#define PLUS 1
#define HASH 2
#define SPACE 4
#define ZERO 8
#define HYPHEN 16
#define W_ASTERISK 32
#define P_ASTERISK 64
#define PRECISION 128
#define LONG 256
#define SHORT 512

#define MAX_INDEX_INT (int)((sizeof(int) * 8) - 1)

/**
 * struct print_flags - format character and value corresponding to a flag
 * @s: format char that indicates a flag to be used
 * @m_val: value to be added to a mask int
 *
 * Description: a finder function looks at s's to see if s's  match characters
 * that come after a '%' in format, and then adds the m_val to a masking int.
 * The int is returned and is fed into a function that prints variadic input
 */
typedef struct print_flags
{
	char s;
	int m_val;
} pr_flag;

/**
 * struct print_function - format character and function
 * @f: format char that indicates function to be returned
 * @func: function that needs to be performed on a variadic input
 *
 * Description: a finder function looks at f's until it finds one that matches
 * the format from central function, and then returns the func that corresponds
 * to that f
 */
typedef struct print_function
{
	char f;
	int (*func)(va_list, int, int, int);
} pr_func;

int _strlen(char *str);

char *i_itoa(int n);

char *li_itoa(long int n);

char *u_itoa(unsigned int n);

char *lu_itoa(unsigned long int n);

int _atoi(char *s);

char *hex_convert(unsigned int n, int let_case);

char *oct_convert(unsigned int n);

char *pointer_convert(unsigned long long int n);

char *str_concat(char *s1, char *s2);

void _memset(char *str, int len, char c);

int mask_check(int mask, int val);

char *rev_str(char *str);

char *rot_13(char *str);

int _printf(const char *format, ...);

int get_flags(const char **format, int *width, int *precis);

int (*get_func(const char **format))(va_list, int, int, int);

int pr_char(va_list ap, int mask, int width, int precis);

int pr_str(va_list ap, int mask, int width, int precis);

int pr_int(va_list ap, int mask, int width, int precis);

int pr_format(va_list ap, int mask, int width, int precis);

int pr_binary(va_list ap, int mask, int width, int precis);

int pr_unsigned(va_list ap, int mask, int width, int precis);

int pr_octal(va_list ap, int mask, int width, int precis);

int pr_hex_low(va_list ap, int mask, int width, int precis);

int pr_hex_cap(va_list ap, int mask, int width, int precis);

int pr_ascii_of_non_printing(va_list ap, int mask, int width, int precis);

int pr_pointer(va_list ap, int mask, int width, int precis);

int pr_rev(va_list ap, int mask, int width, int precis);

int pr_rot13(va_list ap, int mask, int width, int precis);

#endif
