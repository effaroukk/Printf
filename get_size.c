#include "main.h"

/**
 * get_size - Calculating  argument size
 * @format: Formatted string of arguments
 * @z: List of arg
 * Return: size
 */
int get_size(const char *format, int *z)
{
	int curr_z = *z + 1;
	int size = 0;

	if (format[curr_z] == 'l')
		size = S_LONG;
	else if (format[curr_z] == 'h')
		size = S_SHORT;

	if (size == 0)
		*z = curr_z - 1;
	else
		*z = curr_z;

	return (size);
}
