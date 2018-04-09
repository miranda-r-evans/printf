#include "holberton.h"

/**
 * _strlen - finds length of a string
 * @str: string to be evaluated
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	while (*str != '\0')
	{
		str++;
		i++;
	}

	return (i);
}

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: the concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	char *new_str = malloc(_strlen(s1) + _strlen(s2) + 1);
	char *ptr = new_str;

	if (new_str == NULL)
		return (NULL);

	if (s1 != NULL)
	{
		while (*s1 != '\0')
		{
			*ptr = *s1;
			s1++;
			ptr++;
		}
	}

	if (s2 != NULL)
	{
		while (*s2 != '\0')
		{
			*ptr = *s2;
			s2++;
			ptr++;
		}
	}

	*ptr = '\0';

	return (new_str);
}

/**
 * _memset - sets the bytes in a buffer to a particular value
 * @str: buffer to be altered
 * @len: amount of bytes to be changed
 * @c: value to change the bytes to
 */
void _memset(char *str, int len, char c)
{
	int i;

	if (str == NULL)
		return;

	for (i = 0; i < len; i++, str++)
		*str = c;

	*str = '\0';
}

/**
 * _atoi - converts a string to an int
 * @s: string to be converted
 *
 * Return: the int represented by the string
 */
int _atoi(char *s)
{
	int n = 0;
	int is_num = FALSE;
	int sign = 1;
	int s_int;

	while (*s)
	{
		if (is_num == TRUE && (*s > '9' || *s < '0'))
			break;
		if (*s == '-')
			sign = -sign;
		if (is_num == FALSE && *s >= '1' && *s <= '9')
		{
			s_int = *s - 48;
			n += s_int;
			n *= sign;
			is_num = TRUE;
		}
		else if (*s >= '0' && *s <= '9')
		{
			s_int = *s - 48;
			if (n >= 0)
				n = (n * 10) + s_int;
			else
				n = (n * 10) - s_int;
		}
		s++;
	}

	if (is_num == FALSE)
		return (0);

	return (n);
}
