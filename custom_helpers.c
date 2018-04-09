#include "holberton.h"

/**
 * mask_check - checks to see if a given flag indicator is present in the mask
 * @mask: mask that may or may not contain the indicator
 * @val: flag indicator to be checked for
 *
 * Return: TRUE if flag indicator is present, FALSE if not
 */
int mask_check(int mask, int val)
{
	if ((mask & val) != 0)
		return (TRUE);

	return (FALSE);
}

/**
 * rev_str - creates a string that is the reverse of the input string
 * @str: string to be reverse
 *
 * Return: the reversed string
 */
char *rev_str(char *str)
{
	char *new_str = malloc(_strlen(str) + 1);

	new_str += _strlen(str);
	*new_str = '\0';

	while (*str != '\0')
	{
		new_str--;
		*new_str = *str;
		str++;
	}

	return (new_str);
}

/**
 * rot_13 - creates the rot_13 encrypted version of the input string
 * @str: string to be converted
 *
 * Return: the encrypted string
 */
char *rot_13(char *str)
{
	char *new_str = malloc(_strlen(str) + 1);
	char *new_ptr = new_str;

	while (*str != '\0')
	{
		if ((*str >= 'a' && *str <= 'm')
		    || (*str >= 'A' && *str <= 'M'))
			*new_ptr = *str + 13;
		else if (*str >= 'n' && *str <= 'z')
			*new_ptr = 'a' + *str - 'n';
		else if (*str >= 'N' && *str <= 'Z')
			*new_ptr = 'A' + *str - 'N';
		else
			*new_ptr = *str;

		str++;
		new_ptr++;
	}

	*new_ptr = '\0';

	return (new_str);
}
