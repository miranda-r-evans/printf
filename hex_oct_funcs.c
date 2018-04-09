#include "holberton.h"

#define GET_INPUT do {						\
		if (mask_check(mask, ZERO) == TRUE &&		\
		    (mask_check(mask, HYPHEN) == TRUE ||	\
		     mask_check(mask, PRECISION) == TRUE))	\
		{						\
			mask = mask ^ ZERO;			\
		}						\
								\
		if (mask_check(mask, W_ASTERISK) == TRUE)	\
			width = va_arg(ap, int);		\
								\
		if (mask_check(mask, P_ASTERISK) == TRUE)	\
			precis = va_arg(ap, int);		\
								\
		n = va_arg(ap, unsigned int);			\
	} while (0)

#define ADD_ZEROS do {							\
		digits = _strlen(buf);					\
		if (precis > digits || (mask_check(mask, ZERO) == TRUE	\
					&& width > digits))		\
		{							\
			if (precis > digits)				\
				len = precis - digits;			\
			else						\
				len = width - digits;			\
			tmp0 = malloc(len + 1);				\
			_memset(tmp0, len, '0');			\
			tmp1 = str_concat(tmp0, buf);			\
			free(tmp0);					\
			free(buf);					\
			buf = tmp1;					\
		}							\
	} while (0)

#define PRINT do {							\
		if (mask_check(mask, HYPHEN) == TRUE)			\
			j = write(STDOUT_FILENO, buf, _strlen(buf));	\
									\
		if (width > _strlen(buf))				\
		{							\
			len = width - _strlen(buf);			\
			tmp0 = malloc(len + 1);				\
			_memset(tmp0, len, ' ');			\
			i = write(STDOUT_FILENO, tmp0, len);		\
			free(tmp0);					\
		}							\
									\
		if (mask_check(mask, HYPHEN) == FALSE)			\
			j = write(STDOUT_FILENO, buf, _strlen(buf));	\
	} while (0)

/**
 * pr_octal - prints the octal version of an unsigned int
 * @ap: list of variadic input
 * @mask: indicates flags
 * @width: field width (spacing)
 * @precis: precision (digits)
 *
 * Return: length of octal
 */
int pr_octal(va_list ap, int mask, int width, int precis)
{
	unsigned int n;
	int i;
	int j = 0;
	int digits;
	int len;
	char *buf;
	char *tmp0;
	char *tmp1;

	GET_INPUT;

	buf = oct_convert(n);

	if (mask_check(mask, HASH) == TRUE && n > 0)
	{
		tmp0 = str_concat("0", buf);
		free(buf);
		buf = tmp0;
	}

	ADD_ZEROS;

	PRINT;

	free(buf);

	if (i != -1 && j != -1)
		return (i + j);

	return (-1);
}

/**
 * pr_hex_low - prints an unsigned int in hex (lowercase)
 * @ap: list of variadic input
 * @mask: indicates flags
 * @width: field width (spacing)
 * @precis: precision (digits)
 *
 * Return: length of hex
 */
int pr_hex_low(va_list ap, int mask, int width, int precis)
{
	unsigned int n;
	int i;
	int j = 0;
	int digits;
	int len;
	char *buf;
	char *tmp0;
	char *tmp1;

	GET_INPUT;

	buf = hex_convert(n, LOW);

	ADD_ZEROS;

	if (mask_check(mask, HASH) == TRUE && n > 0)
	{
		tmp0 = str_concat("0x", buf);
		free(buf);
		buf = tmp0;
	}

	PRINT;

	free(buf);

	if (i != -1 && j != -1)
		return (i + j);

	return (-1);
}

/**
 * pr_hex_cap - prints an unsigned int in hex (uppercase)
 * @ap: list of variadic input
 * @mask: indicates flags
 * @width: field width (spacing)
 * @precis: precision (digits)
 *
 * Return: length of hex
 */
int pr_hex_cap(va_list ap, int mask, int width, int precis)
{
	unsigned int n;
	int i;
	int j = 0;
	int digits;
	int len;
	char *buf;
	char *tmp0;
	char *tmp1;

	GET_INPUT;

	buf = hex_convert(n, CAP);

	ADD_ZEROS;

	if (mask_check(mask, HASH) == TRUE && n > 0)
	{
		tmp0 = str_concat("0X", buf);
		free(buf);
		buf = tmp0;
	}

	PRINT;

	free(buf);

	if (i != -1 && j != -1)
		return (i + j);

	return (-1);
}

/**
 * pr_pointer - prints the hex version of an address
 * @ap: list of variadic input
 * @mask: indicates flags
 * @width: field width (spacing)
 * @precis: precision (digits)
 *
 * Return: length of the address in hex
 */
int pr_pointer(va_list ap, __attribute__((unused))int mask, __attribute__((unused))int width, __attribute__((unused))int precis)
{
	void *ptr = va_arg(ap, void *);
	unsigned long long int n = (unsigned long long int)ptr;
	char *buf;
	char *tmp;

	if (ptr == NULL)
		return (write(STDOUT_FILENO, "(nil)", 5));

	buf = pointer_convert(n);

	tmp = str_concat("0x", buf);
	free(buf);
	buf = tmp;

	return (write(STDOUT_FILENO, buf, _strlen(buf)));
}
