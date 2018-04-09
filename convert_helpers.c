#include "holberton.h"

#define SET_UP do {				\
		if (n == 0)			\
		{				\
			*ptr = '0';		\
			ptr++;			\
			*ptr = '\0';		\
			return (buf);		\
		}				\
		while (u_mask <= n >> shift)	\
			u_mask <<= shift;	\
						\
		digit = n / u_mask;		\
		while (digit == 0)		\
		{				\
			n %= u_mask;		\
			u_mask >>= shift;	\
			digit = n / u_mask;	\
		}				\
	} while (0)

/**
 * hex_convert - converts a number to hexadecimal
 * @n: number to be converted
 * @let_case: indicates if lowercase or uppercase letters are to be used
 *
 * Return: a string containing the converted number
 */
char *hex_convert(unsigned int n, int let_case)
{
	unsigned int u_mask = 1;
	unsigned int digit;
	int shift = 4;
	char *buf;
	char *ptr;
	char *array;
	char low_array[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			      'a', 'b', 'c', 'd', 'e', 'f'};
	char cap_array[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			      'A', 'B', 'C', 'D', 'E', 'F'};

	if (let_case == LOW)
		array = low_array;
	else if (let_case == CAP)
		array = cap_array;
	else
		return (NULL);

	buf = malloc(sizeof(unsigned int) * 8 + 2);
	ptr = buf;

	SET_UP;

	while (u_mask > 15)
	{
		digit = n / u_mask;
		*ptr = array[digit];
		ptr++;
		n %= u_mask;
		u_mask >>= shift;
	}

	*ptr = array[n];
	ptr++;
	*ptr = '\0';

	return (buf);
}

/**
 * oct_convert - converts a number to octal
 * @n: number to be converted
 *
 * Return: a string containing the converted number
 */
char *oct_convert(unsigned int n)
{
	unsigned int u_mask = 1;
	unsigned int digit;
	int shift = 3;
	char *buf = malloc(sizeof(unsigned int) * 16 + 2);
	char *ptr = buf;

	SET_UP;

	while (u_mask > 7)
	{
		digit = n / u_mask;
		*ptr = digit + '0';
		ptr++;
		n %= u_mask;
		u_mask >>= shift;
	}

	*ptr = n + '0';
	ptr++;
	*ptr = '\0';

	return (buf);
}

/**
 * pointer_convert - converts an unsigned long long (address of pointer) to hex
 * @n: number to be converted
 *
 * Return: a string containing the converted number
 */
char *pointer_convert(unsigned long long int n)
{
	unsigned long long int u_mask = 1;
	unsigned long long int digit;
	int shift = 4;
	char *buf;
	char *ptr;
	char array[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			  'a', 'b', 'c', 'd', 'e', 'f'};

	buf = malloc(sizeof(unsigned long long int) * 8 + 2);
	ptr = buf;

	SET_UP;

	while (u_mask > 15)
	{
		digit = n / u_mask;
		*ptr = array[digit];
		ptr++;
		n %= u_mask;
		u_mask >>= shift;
	}

	*ptr = array[n];
	ptr++;
	*ptr = '\0';

	return (buf);
}
