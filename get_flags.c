#include "main.h"

/**
 * get_flags - Calculating the active flags
 * @format: Formatted string of arguments
 * @q: a parameter taken
 * Return: Flags
 */
int get_flags(const char *format, int *q)
{
	int w, curr_q;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_q = *q + 1; format[curr_q] != '\0'; curr_q++)
	{
		for (w = 0; FLAGS_CH[w] != '\0'; w++)
			if (format[curr_q] == FLAGS_CH[w])
			{
				flags |= FLAGS_ARR[w];
				break;
			}

		if (FLAGS_CH[w] == 0)
			break;
	}

	*q = curr_q - 1;

	return (flags);
}

