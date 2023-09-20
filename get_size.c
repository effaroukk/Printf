#include "main.h"

/**
 * get_size - Calculating  argument size
 * @format: Formatted string of arguments
 * @z: List of arg
 * Return: sizee
 */
int get_size(const char *format, int *z)
{
	int sizee = 0;
	int curr_z = *z + 1;

	if (format[curr_z] == 'l')
		sizee = S_LONG;
	else if (format[curr_z] == 'h')
		sizee = S_SHORT;

	if (sizee == 0)
		*z = curr_z - 1;
	else
		*z = curr_z;

	return (sizee);
}
