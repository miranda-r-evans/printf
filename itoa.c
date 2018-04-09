#include "holberton.h"

#define ITOA_CODE_BODY do {\
		if (n == 0)			\
		{				\
			*ptr = '0';		\
			ptr++;			\
			*ptr = '\0';		\
			return (buf);		\
		}				\
						\
		while (i_mask <= n / 10)	\
			i_mask *= 10;		\
						\
		if (n / i_mask == 0)		\
		{				\
			n %= i_mask;		\
			i_mask /= 10;		\
		}				\
						\
		while (i_mask > 0)		\
		{				\
			digit = n / i_mask;	\
			*ptr = digit + '0';	\
			ptr++;			\
			n %= i_mask;		\
			i_mask /= 10;		\
		}				\
	} while (0)

/**
 * i_itoa - converts an int to a string
 * @n: number to be converted
 *
 * Return: string containing the int
 */
char *i_itoa(int n)
{
	char *buf = malloc(12);
	char *ptr = buf;
	int i_mask = 1;
	int digit = 0;
	int is_min = FALSE;

	if (n == INT_MIN)
	{
		*ptr = '-';
		ptr++;
		is_min = TRUE;
		n = INT_MAX;
	}

	if (n < 0)
	{
		*ptr = '-';
		ptr++;
		n *= -1;
	}

	ITOA_CODE_BODY;

	if (is_min == TRUE)
		(*(ptr - 1))++;

	*ptr = '\0';

	return (buf);
}

/**
 * li_itoa - converts a long int to a string
 * @n: number to be converted
 *
 * Return: string containing number
 */
char *li_itoa(long int n)
{
	char *buf = malloc(12);
	char *ptr = buf;
	long int i_mask = 1;
	long int digit = 0;
	int is_min = FALSE;

	if (n == LONG_MIN)
	{
		*ptr = '-';
		ptr++;
		is_min = TRUE;
		n = LONG_MAX;
	}

	if (n < 0)
	{
		*ptr = '-';
		ptr++;
		n = -n;
	}

	ITOA_CODE_BODY;

	if (is_min == TRUE)
		(*(ptr - 1))++;

	*ptr = '\0';

	return (buf);
}

/**
 * u_itoa - converts an unsigned int to a string
 * @n: number to be converted
 *
 * Return: string containing number
 */
char *u_itoa(unsigned int n)
{
	char *buf = malloc(12);
	char *ptr = buf;
	unsigned int i_mask = 1;
	unsigned int digit = 0;

	ITOA_CODE_BODY;

	*ptr = '\0';

	return (buf);
}

/**
 * lu_itoa - converts a unsigned long int to a string
 * @n: number to be converted
 *
 * Return: string containing number
 */
char *lu_itoa(unsigned long int n)
{
	char *buf = malloc(12);
	char *ptr = buf;
	unsigned long int i_mask = 1;
	unsigned long int digit = 0;

	ITOA_CODE_BODY;

	*ptr = '\0';

	return (buf);
}
