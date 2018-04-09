#include "holberton.h"

/**
 * pr_binary - prints the binary representation of an unsigned int
 * @ap: list of variadic input
 * @mask: indicates flags
 * @width: field width (spacing)
 * @precis: precision (digits)
 *
 * Return: length of the binary
 */
int pr_binary(va_list ap, __attribute__((unused))int mask,
	      __attribute__((unused))int width,
	      __attribute__((unused))int precis)
{
	unsigned int b_mask = 1;
	unsigned int n = va_arg(ap, unsigned int);
	char buf[MAX_INDEX_INT + 2];
	char *ptr = buf;

	b_mask = b_mask << (MAX_INDEX_INT - 1);

	while ((b_mask & n) == 0 && b_mask > 1)
		b_mask = b_mask >> 1;

	while (b_mask > 0)
	{
		if ((b_mask & n) > 0)
			*ptr = '1';
		else
			*ptr = '0';

		b_mask = b_mask >> 1;
		ptr++;
	}
	ptr = '\0';

	return (write(STDOUT_FILENO, buf, _strlen(buf)));
}

/**
 * pr_ascii_of_non_printing - prints the ascii value of non-printing characters
 * e.g. newline, tab
 * @ap: list of variadic input
 * @mask: indicates flags
 * @width: field width (spacing)
 * @precis: precision (digits)
 *
 * Return: length of value printed (plus 2 for "0x")
 */
int pr_ascii_of_non_printing(va_list ap, __attribute__((unused))int mask,
			     __attribute__((unused))int	width,
			     __attribute((unused))int precis)
{
	char *str = va_arg(ap, char *);
	char *holder = str;
	char *buf;
	int write_len = 0;
	int i;
	int total_len = 0;

	while (*str != '\0')
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			if (holder < str)
			{
				i = write(STDOUT_FILENO, holder, write_len);
				if (i != -1)
					total_len += i;
				holder = str;
				write_len = 0;
				while ((*holder > 0 && *holder < 32)
				       || *holder >= 127)
					holder++;
			}
			total_len += write(STDOUT_FILENO, "\\x", 2);
			buf = hex_convert((unsigned int)*str, CAP);

			if (_strlen(buf) == 0)
				total_len += write(STDOUT_FILENO, "00", 2);

			if (_strlen(buf) == 1)
				total_len += write(STDOUT_FILENO, "0", 1);

			total_len += write(STDOUT_FILENO, buf,
					   _strlen(buf));
			free(buf);
		}
		else
			write_len++;

		str++;
	}

	return (total_len);
}

/**
 * pr_rev - prints a string in reverse
 * @ap: list of variadic input
 * @mask: indicates flags
 * @width: field width (spacing)
 * @precis: precision (digits)
 *
 * Return: length of string
 */
int pr_rev(va_list ap, __attribute__((unused))int mask,
	   __attribute__((unused))int width, __attribute__((unused))int precis)
{
	char *str = va_arg(ap, char *);
	char *pr_str = rev_str(str);
	int i = write(STDOUT_FILENO, pr_str, _strlen(pr_str));

	free(pr_str);

	return (i);
}

/**
 * pr_rot13 - prints the rot13 encrypted version of a string
 * @ap: list of variadic input
 * @mask: indicates flags
 * @width: field width (spacing)
 * @precis: precision (digits)
 *
 * Return: length of string
 */
int pr_rot13(va_list ap, __attribute__((unused))int mask,
	     __attribute__((unused))int width, __attribute__((unused))int precis)
{
	char *str = va_arg(ap, char *);
	char *pr_str = rot_13(str);
	int i = write(STDOUT_FILENO, pr_str, _strlen(pr_str));

	free(pr_str);

	return (i);
}
