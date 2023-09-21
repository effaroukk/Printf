#include "main.h"

/**
 * get_size - Extract size modifier from a format string
 * @format: The formatted string
 * @position: Pointer to the current position in the format string
 *
 * Return: Size modifier ('l' for long, 'h' for short, 0 for none)
 */
int get_size(const char *format, int *position)
{
	int size_modifier = 0;
	int ef_position = *position + 1;

	if (format[ef_position] == 'l')
	{
	size_modifier = 'l';
	}
	else if (format[ef_position] == 'h')
	{
	size_modifier = 'h';
	}
	if (size_modifier == 0)
	{
		*position = ef_position - 1;
	}
	else
	{
	*position = ef_position;
	}

	return (size_modifier);
}

