#include "main.h"

/**
 * get_size - Calculate size modifier for the next format specifier
 * @format: The format string
 * @position: Pointer to the current position in the format string
 *
 * Return: Size modifier (0 for none, 'l' for long, 'h' for short)
 */
int get_size(const char *format, size_t *position)
{
	int size_modifier = 0;

	if (format[*position] == 'l')
	{
		size_modifier = 'l';
		(*position)++;
	}
	else if (format[*position] == 'h')
	{
		size_modifier = 'h';
		(*position)++;
	}

	return (size_modifier);
}

