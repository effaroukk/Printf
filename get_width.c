#include "main.h"

/**
 * get_width - to calculate the width to be printed
 * @format: Formatted string of the arguments.
 * @k: arguments list
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *k, va_list list)
{
	int curr_k;
	int width = 0;

	for (curr_k = *k + 1; format[curr_k] != '\0'; curr_k++)
	{
		if (is_digit(format[curr_k]))
		{
			width *= 10;
			width += format[curr_k] - '0';
		}
		else if (format[curr_k] == '*')
		{
			curr_k++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*k = curr_k - 1;

	return (width);
}

