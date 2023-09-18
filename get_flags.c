
#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: The printed arguments are printed in this formatted string
 * @i: The taken parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, current_i;
	int flags = 0;
	const char flags_ch[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flags_array[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		for (j = 0; flags_ch[j] != '\0'; j++)
			if (format[current_i] == flags_ch[j])
			{
				flags |= flags_array[j];
				break;
			}

		if (flags_ch[j] == 0)
			break;
	}

	*i = current_i - 1;

	return (flags);
}
