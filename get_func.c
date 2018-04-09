#include "holberton.h"

/**
 * get_flags - checks for flags
 * @format: format from central function
 *
 * Return: an int that indicates flags
 */
int get_flags(const char **format, int *width, int *precis)
{
	int mask = 0;

	pr_flag flags[] = {
		{'+', PLUS},
		{'#', HASH},
		{' ', SPACE},
		{'0', ZERO},
		{'-', HYPHEN},
		{'\0', 0}
	};
	pr_flag *flag_ptr = flags;

	pr_flag len_mod[] = {
		{'l', LONG},
		{'h', SHORT},
		{'\0', 0}
	};
	pr_flag *len_ptr = len_mod;

	*width = 0;
	*precis = 0;

	while (flag_ptr->s != '\0')
	{
		if (flag_ptr->s == **format && (mask & flag_ptr->m_val) == 0)
		{
			mask = mask | flag_ptr->m_val;
			flag_ptr = flags;
			(*format)++;
		}
		else
			flag_ptr++;
	}

	if (**format == '*')
	{
		mask = mask | W_ASTERISK;
		(*format)++;
	}
	else if (**format >= '0' && **format <= '9')
	{
		*width = _atoi((char *)*format);
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}

	if (**format == '.')
	{
		mask = mask | PRECISION;
		(*format)++;
		if (**format == '*')
		{
			mask = mask | P_ASTERISK;
			(*format)++;
		}
		else if (**format >= '0' && **format <= '9')
		{
			*precis = _atoi((char *)*format);
			while (**format >= '0' && **format <= '9')
				(*format)++;
		}
	}

	while (len_ptr->s != '\0')
	{
		if (len_ptr->s == **format)
		{
			mask = mask | len_ptr->m_val;
			(*format)++;
			break;
		}
		len_ptr++;
	}

	return (mask);
}

/**
 * get_func - finds the function needed to print a particular data type
 * @format: format from central function
 *
 * Return: the needed function
 */
int (*get_func(const char **format))(va_list, int, int, int)
{
	pr_func functions[] = {
		{'c', pr_char},
		{'s', pr_str},
		{'i', pr_int},
		{'d', pr_int},
		{'b', pr_binary},
		{'u', pr_unsigned},
		{'o', pr_octal},
		{'x', pr_hex_low},
		{'X', pr_hex_cap},
		{'S', pr_ascii_of_non_printing},
		{'p', pr_pointer},
		{'r', pr_rev},
		{'R', pr_rot13},
		{'\0', pr_format}
	};
	pr_func *func_ptr = functions;

	while (func_ptr->f != **format && func_ptr->f != '\0')
	{
		func_ptr++;
	}

	(*format)++;

	return (func_ptr->func);
}
