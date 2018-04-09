#include "holberton.h"

/**
 * _printf - prints a formatted string with variadic input
 * @format: format of printed string
 *
 * Return: length of printed string
 */
int _printf(const char *format, ...)
{
	va_list ap;
	const char *holder = format;
	int width;
	int precis;
	int total_len = 0;
	int write_len = 0;
	int i;
	int mask;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			write(STDOUT_FILENO, holder, write_len);
			holder = format;
			write_len = 0;
			format++;
			if (*format == '%')
			{
				write(STDOUT_FILENO, "%", 1);
				format++;
				total_len++;
			}
			else
			{
				mask = get_flags(&format, &width, &precis);
				i = (get_func(&format))(ap, mask, width, precis);
				if (i == -2)
				{
					total_len += write(STDOUT_FILENO,
							   holder,
							   format - holder - 1);
				}
				if (i > 0)
					total_len += i;
			}

			holder = format;
		}
		else
		{
			total_len++;
			write_len++;
			format++;
		}
	}
	write(STDOUT_FILENO, holder, write_len);

	va_end(ap);

	return (total_len);
}
