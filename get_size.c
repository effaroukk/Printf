#include "main.h"

/**
 * get_size - Calculating  argument size
 * @format: arguments of formatted string
 * @z: arg list
 * Return: sizee
 */
int get_size(const char *format, int *z)
{
	int sizee = 0, curl_z = *z + 1;

	if (format[curl_z] == 'l')
		sizee = S_LONG;
	else if (format[curl_z] == 'h')
		sizee = S_SHORT;

	if (sizee == 0)
		*z = curl_z - 1;
	else
		*z = curl_z;

	return (sizee);
}
