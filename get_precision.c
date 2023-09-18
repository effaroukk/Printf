#include "main.h"

/**
 * get_precision - Calculating the printing precision
 * @format: Formatting string arguments
 * @list: list of arguments.
 * @z: List of arguments to be printed.
 * Return: Precision.
 */
int get_precision(const char *format, int *z, va_list list)
{
	int curr_z = *z + 1;
	int precision = -1;

	if (format[curr_z] != '.')
		return (precision);

	precision = 0;

	for (curr_z += 1; format[curr_z] != '\0'; curr_z++)
	{
		if (is_digit(format[curr_z]))
		{
			precision *= 10;
			precision += format[curr_z] - '0';
		}
		else if (format[curr_z] == '*')
		{
			curr_z++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*z = curr_z - 1;

	return (precision);
}
